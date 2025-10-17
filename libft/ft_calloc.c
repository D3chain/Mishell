/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:01:39 by echatela          #+#    #+#             */
/*   Updated: 2025/05/04 12:06:19 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (size && count > ~0UL / size)
		return (NULL);
	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	return (ft_memset(arr, 0, count * size));
}

/* int main(void)
{
    int *arr = ft_calloc(5, sizeof(int));
    int i = 0;

    while (i < 5)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
        i++;
    }
    free(arr);
    return 0;
} */