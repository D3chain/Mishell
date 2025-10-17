/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:56:15 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 11:06:55 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "vec.h"
#include "libft.h"

int	vec_init(struct s_vec *v, int esize)
{
	if (!v || esize <= 0)
		return (1);
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
	v->esize = esize;
	return (0);
}

void	vec_free(struct s_vec *v, void (*free_one)(void *))
{
	int	i;

	if (!v)
		return ;
	i = -1;
	if (free_one)
		while (++i < v->len)
			free_one((char *)v->data + (size_t)i * v->esize);
	if (v->data)
		free(v->data);
	v->data = NULL;
	v->len = 0;
	v->cap = 0;
}

int	vec_reserve(struct s_vec *v, int need)
{
	void	*p;
	int		ncap;

	if (need < v->cap)
		return (0);
	ncap = 16;
	if (v->cap)
		ncap = v->cap * 2;
	while (ncap < need - 1)
		ncap *= 2;
	p = ft_calloc((size_t)ncap, (size_t)v->esize);
	if (!p)
		return (1);
	if (v->data)
	{
		ft_memcpy(p, v->data, (size_t)v->len * v->esize);
		free(v->data);
	}
	v->data = p;
	v->cap = ncap;
	return (0);
}

int	vec_push(struct s_vec *v, const void *elem)
{
	if (vec_reserve(v, v->len + 1) != 0)
		return (1);
	ft_memcpy((char *)v->data + (size_t)v->len * v->esize, elem, v->esize);
	v->len++;
	return (0);
}
