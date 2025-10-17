/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:11:22 by echatela          #+#    #+#             */
/*   Updated: 2025/04/30 11:29:49 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	needle_len = ft_strlen(needle);
	while (*haystack && len-- >= needle_len)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

// int main(void)
// {
//     char *s = "Hello World";
//     char *res;
//     res = ft_strnstr(s, "World", 11);
//     printf("Found: %s\n", res);
//     res = ft_strnstr(s, "World", 5);
//     printf("Found: %s\n", res ? res : "Not found");
//     res = ft_strnstr(s, "", 5);
//     printf("Found: %s\n", res);
// }
