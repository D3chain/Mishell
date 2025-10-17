/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:12:11 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 15:12:32 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s += i));
		i--;
	}
	return (NULL);
}

// int main(void)
// {
//     char str[] = "bonjour";
//     char *s;
//     // Test normal
//     s = ft_strrchr(str, 'o');
//     if (s)
//         printf("1st occ of 'o': %s\n", s);
//     else
//         printf("'o' not found.\n");
//     // Test avec '\0'
//     s = ft_strrchr(str, '\0');
//     if (s)
//         printf("1st occ of '\\0': %p (expected: %p)\n", s, str + 7); 
// '\0' est à la fin
//     else
//         printf("'\\0' not found.\n");
//     return 0;
// }