/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:12:55 by echatela          #+#    #+#             */
/*   Updated: 2025/05/01 15:44:16 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	if (!n)
		return (0);
	p1 = s1;
	p2 = s2;
	while (--n && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

/* int main(void)
{
    char a[] = "Bonjour";
    char b[] = "Bonjour";
    char c[] = "Bonjout";
    char d[] = "Bonjoul";
    printf("a vs b: %d\n", ft_memcmp(a, b, 7)); 
devrait être 0
    printf("a vs c: %d\n", ft_memcmp(a, c, 7)); 
devrait être < 0 (car 'r' < 't')
    printf("a vs d: %d\n", ft_memcmp(a, d, 7)); 
devrait être > 0 (car 'r' > 'l')
    // Pour tester sur une longueur plus courte
    printf("a vs c (n = 5): %d\n", ft_memcmp(a, c, 5)); 
devrait être 0 car les 5 premiers caractères sont les mêmes
} */