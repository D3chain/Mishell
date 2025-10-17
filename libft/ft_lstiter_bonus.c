/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:25:26 by echatela          #+#    #+#             */
/*   Updated: 2025/04/28 11:41:27 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f(void *content)
// {
// 	printf("%s\n", (char *)content);
// }
// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*node1 = ft_lstnew(ft_strdup("node1"));
// 	t_list	*node2 = ft_lstnew(ft_strdup("node2"));
// 	t_list	*node3 = ft_lstnew(ft_strdup("node3"));
// 	ft_lstadd_back(&list, node1);
// 	ft_lstadd_back(&list, node2);
// 	ft_lstadd_back(&list, node3);
// 	printf("Supposed to print every content of list: node1, node2, node3 :\n");
// 	ft_lstiter(list, f);
// 	return (0);
// }