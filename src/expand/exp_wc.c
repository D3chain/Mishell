/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_wc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 20:16:40 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 17:27:26 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exp.h"

static int	dot(const char *pat, char *entry)
{
	int	i;
	int	sq;
	int	dq;

	i = -1;
	sq = 0;
	dq = 0;
	if (entry[0] != '.')
		return (0);
	while (pat[++i])
	{
		if (check_quote(pat[i], &sq, &dq))
			continue ;
		return (pat[i] == '.');
	}
	return (0);
}

int	is_expandable(const char *ref, int in_sq, int in_dq)
{
	int	i;

	i = -1;
	while (ref[++i])
	{
		check_quote(ref[i], &in_sq, &in_dq);
		if (ref[i] == '*' && !in_sq && !in_dq)
			return (1);
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

static int	expand_wc_vec(char *ref, struct s_vec *exp_vec)
{
	DIR				*dir;
	struct dirent	*entry;
	char			*name;

	if (!is_expandable(ref, 0, 0))
	{
		name = ft_strdup(ref);
		if (!name || vec_push(exp_vec, &name) != 0)
			return (arg_free(name), 1);
		return (0);
	}
	dir = opendir(".");
	if (!dir)
		return (vec_free(exp_vec, arg_free), 1);
	entry = readdir(dir);
	while (entry != NULL)
	{
		if ((entry->d_name[0] != '.' || dot(ref, entry->d_name))
			&& wc_match(entry->d_name, ref, 0, 0))
		{
			name = ft_strdup(entry->d_name);
			if (!name || vec_push(exp_vec, &name) != 0)
				return (closedir(dir), 1);
		}
		entry = readdir(dir);
	}
	return (closedir(dir), 0);
}

int	expand_wc(char **ref, struct s_vec *argv)
{
	struct s_vec	tmp_vec;
	int				i;

	vec_init(&tmp_vec, sizeof(char *));
	if (expand_wc_vec(*ref, &tmp_vec) != 0)
		return (vec_free(&tmp_vec, arg_free), err_per(1, "expand"));
	if (!argv)
	{
		if (tmp_vec.len > 1)
			return (vec_free(&tmp_vec, arg_free),
				err_msg(1, *ref, "ambiguous redirect"));
		if (tmp_vec.len == 0)
			return (0);
		free(*ref);
		*ref = ft_strdup(((char **)tmp_vec.data)[0]);
		if (!*ref)
			return (vec_free(&tmp_vec, arg_free), err_per(1, "expand"));
		return (vec_free(&tmp_vec, arg_free), 0);
	}
	i = -1;
	while (++i < tmp_vec.len)
		if (vec_push(argv, &((char **)tmp_vec.data)[i]) != 0)
			return (vec_free(&tmp_vec, arg_free), err_per(1, "expand"));
	(free(tmp_vec.data), free(*ref));
	return (0);
}
