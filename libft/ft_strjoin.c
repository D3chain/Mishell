/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:08:49 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 15:09:15 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, len1);
	ft_memcpy(dst + len1, s2, len2);
	dst[len1 + len2] = '\0';
	return (dst);
}

// int main()
// {
//     char *s1 = "Hello ";
//     char *s2 = "World!";
//     char *result = ft_strjoin(s1, s2);

//     if (result)
//     {
//         printf("%s\n", result);
//         free(result);
//     }
//     else
//     {
//         printf("Memory allocation failed!\n");
//     }
//     return 0;
// }