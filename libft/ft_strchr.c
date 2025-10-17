/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:07:33 by echatela          #+#    #+#             */
/*   Updated: 2025/04/30 12:08:22 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (!(char)c)
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
//     char str[] = "bonjour";
//     char *s;
//     // Test normal
//     s = ft_strchr(str, 'o');
//     if (s)
//         printf("1st occ of 'o': %s\n", s);
//     else
//         printf("'o' not found.\n");
//     // Test avec '\0'
//     s = ft_strchr(str, '\0');
//     if (s)
//         printf("1st occ of '\\0': %p (expected: %p)\n", s, str + 7);
// '\0' est à la fin
//     else
//         printf("'\\0' not found.\n");
//     return 0;
// }