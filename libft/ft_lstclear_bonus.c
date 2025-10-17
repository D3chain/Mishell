/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:57:23 by echatela          #+#    #+#             */
/*   Updated: 2025/05/12 12:21:11 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/* void	del(void *content)
{
	(void)content;
}

int	main(void)
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
	ft_lstclear(&list, del);
	if (list == NULL)
		printf("[OK] clear done correctly!\n");
	else
		printf("[KO] clear not done correctly!\n");
	return (0);
} */