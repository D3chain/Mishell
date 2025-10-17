/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 15:08:29 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 15:08:40 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// void flip_case(unsigned int i, char *c)
// {
//     if (i % 2 == 0)
//         *c = ft_tolower(*c);
//     else
//         *c = ft_toupper(*c);
// }

// int main(int ac, char **av)
// {
//     (void)ac;

//     printf("Original : %s\n", av[1]);
//     ft_striteri(av[1], flip_case);
//     printf("Modifié  : %s\n", av[1]);
//     return (0);
// }