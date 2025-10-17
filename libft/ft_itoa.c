/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:08:22 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 14:08:47 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int		len;
	long	nb;

	nb = n;
	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		len++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	nb = n;
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len-- - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

// int main(int ac, char **av)
// {
//     (void)ac;
//     printf("%s\n", ft_itoa(atoi(av[1])));
// }