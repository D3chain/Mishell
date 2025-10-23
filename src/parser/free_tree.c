/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:08:41 by echatela          #+#    #+#             */
/*   Updated: 2025/10/23 11:51:47 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_par.h"
#include "vec.h"

void	free_simple(struct s_node *simple)
{
	int	i;

	if (simple->u.s_simple.argv && simple->u.s_simple.argv[0])
	{
		i = -1;
		while (simple->u.s_simple.argv[++i])
			free(simple->u.s_simple.argv[i]);
		free(simple->u.s_simple.argv);
		simple->u.s_simple.argv = NULL;
	}
	if (simple->u.s_simple.redv && simple->u.s_simple.redv[0].arg)
	{
		i = -1;
		while (simple->u.s_simple.redv[++i].arg)
		{
			free(simple->u.s_simple.redv[i].arg);
			if (simple->u.s_simple.redv[i].type == R_HDOC
				&& simple->u.s_simple.redv[i].fd[0] != -1)
				close_set(&simple->u.s_simple.redv[i].fd[0]);	
		}
		free(simple->u.s_simple.redv);
		simple->u.s_simple.redv = NULL;
	}
}

void	free_pipeline(struct s_node *pipeline)
{
	int	i;

	i = -1;
	while (++i < pipeline->u.s_pipeline.n)
		free_node(pipeline->u.s_pipeline.v[i]);
	free(pipeline->u.s_pipeline.v);
	pipeline->u.s_pipeline.v = NULL;
}

void	free_and_or(struct s_node *and_or)
{
	free_node(and_or->u.s_andor.lhs);
	and_or->u.s_andor.lhs = NULL;
	free_node(and_or->u.s_andor.rhs);
	and_or->u.s_andor.rhs = NULL;
}

void	free_node(struct s_node *node)
{
	if (!node)
		return ;
	if (node->kind == N_SIMPLE)
		free_simple(node);
	else if (node->kind == N_SUBSHELL)
	{
		free_node(node->u.s_subshell.list);
		node->u.s_subshell.list = NULL;
	}
	else if (node->kind == N_PIPELINE)
		free_pipeline(node);
	else if (node->kind == N_ANDOR)
		free_and_or(node);
	free(node);
}
