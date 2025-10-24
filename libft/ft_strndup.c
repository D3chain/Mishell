/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:37:10 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/21 16:37:51 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int size)
{
	char	*s2;
	int		i;

	s2 = malloc(sizeof(char) * size + 1);
	if (!s2)
		return (NULL);
	i = -1;
	while (s1[++i] && i < size)
		s2[i] = s1[i];
	s2[i] = '\0';
	return (s2);
}
