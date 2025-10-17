/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:26:50 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 09:39:24 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	is_blank(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	is_meta(int c)
{
	return (c == '|' || c == '&' || c == '(' || c == ';'
		|| c == ')' || c == '<' || c == '>');
}

int	check_quote(char c, int *in_sq, int *in_dq)
{
	if (c == '\'' && !*in_dq)
	{
		*in_sq = !*in_sq;
		return (1);
	}
	if (c == '\"' && !*in_sq)
	{
		*in_dq = !*in_dq;
		return (1);
	}
	return (0);
}

int	are_quotes_closed(char *s)
{
	int	i;
	int	sq;
	int	dq;

	sq = 0;
	dq = 0;
	i = -1;
	while (s[++i])
		check_quote(s[i], &sq, &dq);
	if (sq || dq)
		return (0);
	return (1);
}

void	free_tab_str(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}
