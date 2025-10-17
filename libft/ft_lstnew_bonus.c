/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:37:39 by echatela          #+#    #+#             */
/*   Updated: 2025/04/27 14:12:14 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int	main(void)
// {
// 	char	*str = "Hello, World!";
// 	t_list	*node;
// 	node = ft_lstnew(str);
// 	if (!node)
// 		return (printf("Erreur d'allocation\n"), 1);
// 	if (node->content == str)
// 		printf("[OK] content est correct : %s\n", (char *)node->content);
// 	else
// 		printf("[KO] content incorrect\n");
// 	if (node->next == NULL)
// 		printf("[OK] next est bien NULL\n");
// 	else
// 		printf("[KO] next n'est pas NULL\n");
// 	free(node);
// 	return (0);
// }