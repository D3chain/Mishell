/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:00:00 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 14:00:02 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// int main()
// {
//     const char *str1 = "   -123abc";
//     const char *str2 = "-2147483648";
//     const char *str3 = "  +42abc";

//     printf("Test 1: '%s' -> %d\n", str1, ft_atoi(str1));  // -123
//     printf("Test 2: '%s' -> %d\n", str2, ft_atoi(str2));  // 42
//     printf("Test 3: '%s' -> %d\n", str3, ft_atoi(str3));  // 42

//     return 0;
// }