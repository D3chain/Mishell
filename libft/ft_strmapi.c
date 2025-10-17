/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:10:31 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 15:10:54 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char flip_case(unsigned int i, char c)
// {
//     if (i % 2 == 0)
//         return ft_tolower(c);
//     else
//         return ft_toupper(c);
// }
// int main(int ac, char **av)
// {
//     (void)ac;
//     char *res;
//     res = ft_strmapi(av[1], flip_case);
//     if (!res)
//     {
//         printf("Erreur d'allocation mémoire.\n");
//         return (1);
//     }
//     printf("Original : %s\n", av[1]);
//     printf("Modifié  : %s\n", res);
//     free(res);
//     return (0);
// }