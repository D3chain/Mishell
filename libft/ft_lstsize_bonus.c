/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:09:14 by echatela          #+#    #+#             */
/*   Updated: 2025/04/25 14:54:42 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*node1 = ft_lstnew("node1");
// 	t_list	*node2 = ft_lstnew("node2");
// 	t_list	*node3 = ft_lstnew("node3");
// 	t_list	*node4 = ft_lstnew("node4");
// 	t_list	*node5 = ft_lstnew("node5");
// 	ft_lstadd_back(&list, node1);
// 	ft_lstadd_back(&list, node2);
// 	ft_lstadd_back(&list, node3);
// 	ft_lstadd_back(&list, node4);
// 	ft_lstadd_back(&list, node5);
// 	if (ft_lstsize(list) == 5)
// 		printf("[OK] List size is 5\n");
// 	else
// 		printf("[KO] Wrong size\n");
// 	return (0);
// }