/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_wc_red.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:53:54 by echatela          #+#    #+#             */
/*   Updated: 2025/10/18 18:13:00 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exp.h"

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

int	expand_wc_red(char **p_red)
{
	struct s_vec	tmp_vec;
	
	vec_init(&tmp_vec, sizeof(char *));
	if (expand_arg_in_vec(&tmp_vec, *p_red) != 0)
	{
		vec_free(&tmp_vec, arg_free);
		return (err_per(1, "expand"));
	}
	if (tmp_vec.len > 1)
	{
		vec_free(&tmp_vec, arg_free);
		return (err_msg(1, *p_red, "ambiguous redirect"));
	}
	if (tmp_vec.len == 0)
		return (0);
	free(*p_red);
	*p_red = ft_strdup(((char **)tmp_vec.data)[0]);
	if (!*p_red)
	{
		vec_free(&tmp_vec, arg_free);
		return (err_per(1, "expand"));
	}
	free(tmp_vec.data);
	return (0);
}
