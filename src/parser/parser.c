/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:43:26 by echatela          #+#    #+#             */
/*   Updated: 2025/10/15 17:33:59 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static struct s_node	*par_pipe(struct s_tok *toks, int *i, int *st)
{
	struct s_node	*new;
	struct s_vec	pipevec;

	new = par_command(toks, i, st);
	if (!new)
		return (NULL);
	if (toks[*i].type == T_PIPE)
	{
		vec_init(&pipevec, sizeof(new));
		if (vec_push(&pipevec, &new) != 0)
			return (free_node(new), NULL);
		while (toks[*i].type == T_PIPE)
		{
			new = (++(*i), par_command(toks, i, st));
			if (!new || vec_push(&pipevec, &new) != 0)
				return (vec_free(&pipevec, node_free), NULL);
		}
		new = ft_calloc(1, sizeof(*new));
		if (!new)
			return (NULL);
		new->kind = N_PIPELINE;
		new->u.s_pipeline.n = pipevec.len;
		new->u.s_pipeline.v = pipevec.data;
	}
	return (new);
}

static struct s_node	*par_and_or(struct s_tok *toks, int *i, int *st)
{
	struct s_node	*new;
	struct s_node	*tmp;

	new = par_pipe(toks, i, st);
	if (!new)
		return (NULL);
	while (toks[*i].type == T_AND || toks[*i].type == T_OR)
	{
		tmp = new;
		new = malloc(sizeof(*new));
		if (!new)
			return (free(tmp), NULL);
		new->kind = N_ANDOR;
		new->u.s_andor.op = toks[*i].type - 2;
		new->u.s_andor.lhs = tmp;
		new->u.s_andor.rhs = (++(*i), par_pipe(toks, i, st));
		if (!new->u.s_andor.rhs)
			return (free(new->u.s_andor.lhs), free(new), NULL);
	}
	return (new);
}

struct s_node	*par_list(struct s_tok *toks, int *i, int *st)
{
	struct s_node	*new;

	new = par_and_or(toks, i, st);
	if (!new)
		return (NULL);
	return (new);
}

int	par_build(struct s_tok *toks, struct s_node **root)
{
	int	i;
	int	st;

	i = 0;
	st = 0;
	*root = par_list(toks, &i, &st);
	if (st == 1)
		return (err_per(2, "parser"));
	if (st == 2)
		return (err_syn("newline"));
	if (st == 3 || toks[i].type != T_EOF)
		return (err_syn(toks[i].lex));
	return (0);
}
