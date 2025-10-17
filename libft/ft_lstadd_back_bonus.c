/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:24:44 by echatela          #+#    #+#             */
/*   Updated: 2025/04/30 12:16:06 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
		ft_lstadd_front(lst, new);
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
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
// 	if (ft_lstlast(list) == node5)
// 		printf("[OK] Last is node5\n");
// 	else
// 		printf("[KO] Wrong end\n");
// 	return (0);
// }