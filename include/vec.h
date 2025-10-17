/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:47:21 by echatela          #+#    #+#             */
/*   Updated: 2025/10/11 17:19:26 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

struct s_vec
{
	void	*data;
	int		len;
	int		cap;
	int		esize;
};

int		vec_init(struct s_vec *v, int esize);
void	vec_free(struct s_vec *v, void (*free_one)(void *));
int		vec_reserve(struct s_vec *v, int need);
int		vec_push(struct s_vec *v, const void *elem);

void	tok_free(void *p);
void	node_free(void *p);
void	arg_free(void *p);
void	redir_free(void *p);

#endif