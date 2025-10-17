/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:21:04 by echatela          #+#    #+#             */
/*   Updated: 2025/04/30 12:16:36 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* int	main(void)
{
	t_list	*list = NULL;
	t_list	*node1 = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");
	t_list	*node3 = ft_lstnew("node3");
	t_list	*node4 = ft_lstnew("node4");
	t_list	*node5 = ft_lstnew("node5");
	ft_lstadd_back(&list, node1);
	ft_lstadd_back(&list, node2);
	ft_lstadd_back(&list, node3);
	ft_lstadd_back(&list, node4);
	ft_lstadd_back(&list, node5);
	if (ft_lstlast(list) == node5)
		printf("[OK] Last is node5\n");
	else
		printf("[KO] Wrong end\n");
	return (0);
} */