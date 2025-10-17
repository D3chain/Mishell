/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_unquote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 07:55:23 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 08:57:26 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	exp_unquote_str(char *str, int sq, int dq)
{
	int	is_quote;
	int	len;
	int	i;
	int	j;

	is_quote = 0;
	len = ft_strlen(str);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (check_quote(str[i], &sq, &dq))
			is_quote = 1;
		else if (i == j)
			j++;
		else
			str[j++] = str[i];
		i++;
	}
	while (j < len)
		str[j++] = 0;
	return (is_quote);
}
