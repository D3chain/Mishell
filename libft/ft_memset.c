/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:42:21 by echatela          #+#    #+#             */
/*   Updated: 2025/04/29 12:11:20 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
		*(p++) = (unsigned char)c;
	return (b);
}

// int main(void)
// {
//     char str[20] = "Hello, world!";
//     printf("Avant memset  : %s\n", str);

//     ft_memset(str + 7, '*', 5);  // Remplace "world" par "*****"
//     printf("Après memset  : %s\n", str);

//     return 0;
// }