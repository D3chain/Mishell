/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:55:35 by echatela          #+#    #+#             */
/*   Updated: 2025/04/25 14:39:59 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*node1 = ft_lstnew("node 1");
// 	t_list	*node2 = ft_lstnew("node 2");
// 	ft_lstadd_front(&list, node1);
// 	ft_lstadd_front(&list, node2);
// 	t_list	*current = list;
// 	while (current)
// 	{
// 		printf("[OK] contenu : %s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	free(node1);
// 	free(node2);
// 	return (0);
// }