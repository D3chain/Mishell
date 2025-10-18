/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_wc_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:14:39 by echatela          #+#    #+#             */
/*   Updated: 2025/10/18 18:17:49 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exp.h"

static int	pat_allows_dot(const char *pat)
{
	int	i;
	int	sq;
	int	dq;

	i = -1;
	sq = 0;
	dq = 0;
	while (pat[++i])
	{
		if (check_quote(pat[i], &sq, &dq))
			continue ;
		return (pat[i] == '.');
	}
	return (0);
}

static int	wc_match(const char *name, const char *pat, int sq, int dq)
{
	if (*pat == 0)
		return (*name == 0);
	if (check_quote(*pat, &sq, &dq))
		return (wc_match(name, pat + 1, sq, dq));
	if (*pat == '*' && !sq && !dq)
	{
		if (wc_match(name, pat + 1, sq, dq))
			return (1);
		if (*name != 0)
			return (wc_match(name + 1, pat, sq, dq));
		return (0);
	}
	if (*name == 0 || *name != *pat)
		return (0);
	return (wc_match(name + 1, pat + 1, sq, dq));
}

static int	push_match_in_vec(struct s_vec *tmp_vec, char *arg)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*name;

	dir = opendir(".");
	if (!dir)
		return (err_per(1, "expand"));
	entry = readdir(dir);
	while (entry)
	{
		if ((entry->d_name[0] != '.' || pat_allows_dot(arg))
			&& wc_match(entry->d_name, arg, 0, 0))
		{
			name = ft_strdup(entry->d_name);
			if (!name || vec_push(tmp_vec, &name) != 0)
			{
				closedir(dir);
				return (1);
			}
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (0);
}

int	expand_arg_in_vec(struct s_vec *tmp_vec, char *arg)
{
	char	*name;

	if (!is_expandable(arg, 0, 0))
	{
		name = ft_strdup(arg);
		if (!name || vec_push(tmp_vec, &name) != 0)
			return (free(name), err_per(1, "expand"));
	}
	else if (push_match_in_vec(tmp_vec, arg) != 0)
		return (1);
	return (0);	
}

int	expand_wc_arg(struct s_vec *arg_vec, char *arg)
{
	struct s_vec	tmp_vec;
	int				i;

	vec_init(&tmp_vec, sizeof(char *));
	if (expand_arg_in_vec(&tmp_vec, arg) != 0)
	{
		vec_free(&tmp_vec, arg_free);
		return (err_per(1, "expand"));
	}
	i = -1;
	while (++i < tmp_vec.len)
	{
		if (vec_push(arg_vec, &((char **)tmp_vec.data)[i]) != 0)
		{
			while (i < tmp_vec.len)
				free(((char **)tmp_vec.data)[i++]);
			free(tmp_vec.data);
			return (err_per(1, "expand"));
		}
	}
	free(tmp_vec.data);
	return (0);
}
