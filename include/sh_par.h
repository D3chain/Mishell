/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_par.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:44:06 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 11:48:40 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PAR_H
# define SH_PAR_H

#include "shell.h"
#include "sh_lex.h"

struct s_tok;
struct s_shell;

enum { N_SIMPLE, N_SUBSHELL, N_PIPELINE, N_ANDOR
};

enum { AO_AND, AO_OR
};

enum { R_IN, R_HDOC, R_OUT, R_APP
};

struct s_redir
{
	int		type;
	char	*arg;
	int		fd[2];
};

struct s_cmd
{
	char			**argv;
	struct s_redir	*redv;
};

struct s_node
{
	int	kind;
	union
	{
		struct s_cmd		s_simple;
		struct	 
		{
			struct s_node	*list;
		} s_subshell;
		struct
		{
			struct s_node	**v;
			int				n;
		} s_pipeline;
		struct
		{
			struct s_node	*lhs;
			int				op;
			struct s_node	*rhs;
		} s_andor;
	} u;
};

int				par_build(struct s_tok *toks, struct s_node **root);
struct s_node	*par_list(struct s_tok *toks, int *i, int *st);
struct s_node	*par_command(struct s_tok *toks, int *i, int *st);

void			free_node(struct s_node *node);
void			free_and_or(struct s_node *and_or);
void			free_pipeline(struct s_node *pipeline);
void			free_simple(struct s_node *simple);

void 			ast_print(struct s_shell *sh, struct s_node *root);

#endif
