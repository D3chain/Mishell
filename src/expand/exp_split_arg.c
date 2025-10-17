/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_split_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:28:07 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 10:07:18 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exp.h"

void	unblank_str(char *str, int sq, int dq)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (i < len)
	{
		check_quote(str[i], &sq, &dq);
		if (is_blank(str[i]) && !sq && !dq)
			;
		else if (i == j)
			j++;
		else
			str[j] = str[i];
		i++;
	}
	while (j < len)
		str[j++] = 0;
}

int	split_arg(struct s_vec *arg_vec, char *arg)
{
	char	*splited;
	int		sq;
	int		dq;
	int		i;

	sq = 0;
	dq = 0;
	while (is_blank(*arg))
		arg++;
	if (!*arg)
		return (0);
	i = -1;
	while (++i)
	{
		check_quote(arg[i], &sq, &dq);
		if (!arg[i] || (is_blank(arg[i]) && !sq && !dq))
		{
			splited = ft_substr(arg, 0, i);
			if (!splited || vec_push(arg_vec, &splited) != 0)
				return (1);
			return (split_arg(arg_vec, arg + i));
		}
	}
	return (0);
}
