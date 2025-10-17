/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:12:08 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 11:54:38 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_par.h"
#include "vec.h"

void	tok_free(void *p)
{
	struct s_tok	*tok;

	tok = p;
	if (tok->lex)
		free(tok->lex);
	tok->lex = NULL;
}

void	node_free(void *p)
{
	struct s_node	**node;

	node = p;
	free_node(*node);
	*node = NULL;
}

void	arg_free(void *p)
{
	char	**arg;

	arg = p;
	free(*arg);
	*arg = NULL;
}

void	redir_free(void *p)
{
	struct s_redir	*redir;

	redir = p;
	free(redir->arg);
	redir->arg = NULL;
}
