/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 10:42:58 by echatela          #+#    #+#             */
/*   Updated: 2025/04/28 11:41:33 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
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
// 	printf("Before clear, content is : %s -> %s -> %s\n",
// 	(char *)node1->content, (char *)node2->content, (char *)node3->content);
// 	ft_lstdelone(node2, del);
// 	return (0);
// }