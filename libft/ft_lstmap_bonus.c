/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:30:17 by echatela          #+#    #+#             */
/*   Updated: 2025/09/17 18:19:33 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	start = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, new_node);
		lst = lst->next;
	}
	return (start);
}

// void	del(void *content)
// {
// 	free(content);
// }
// void	*f(void *content)
// {
// 	return(ft_strjoin((const char *)content, (const char *)"join"));
// }
// int	main(void)
// {
// 	t_list	*list = NULL;
// 	t_list	*new = NULL;
// 	t_list	*node1 = ft_lstnew(ft_strdup("node1"));
// 	t_list	*node2 = ft_lstnew(ft_strdup("node2"));
// 	t_list	*node3 = ft_lstnew(ft_strdup("node3"));
// 	ft_lstadd_back(&list, node1);
// 	ft_lstadd_back(&list, node2);
// 	ft_lstadd_back(&list, node3);
// 	new = ft_lstmap(list, &f, del);
// 	while (new)
// 	{
// 		printf("%s\n", (char *)new->content);
// 		new = new->next;
// 	}
// 	return (0);
// }