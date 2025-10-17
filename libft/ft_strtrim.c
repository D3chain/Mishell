/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:12:44 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 15:14:25 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*s2;

	i = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	s2 = malloc(sizeof(char) * (end - start + 2));
	if (!s2)
		return (NULL);
	while (start <= end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}

// int main()
// {
//     char *s = "  \t  Hello World!  \n  ";
//     char *set = " \t\n";
//     char *trimmed = ft_strtrim(s, set);
//     if (trimmed)
//     {
//         printf("Trimmed string: '%s'\n", trimmed);
//         free(trimmed);
//     }
//     else
//         printf("Memory allocation failed!\n");
//     return 0;
// }