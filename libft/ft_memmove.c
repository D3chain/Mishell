/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:14:39 by echatela          #+#    #+#             */
/*   Updated: 2025/04/30 11:27:15 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		d = (unsigned char *)dst + len;
		s = (const unsigned char *)src + len;
		while (len--)
			*(--d) = *(--s);
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}

// int main(void)
// {
//     char str[] = "HelloWorld";
//     ft_memmove(str + 3, str, 5);
//     printf("Result: %s\n", str);
// }