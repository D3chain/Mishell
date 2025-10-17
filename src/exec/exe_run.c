/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_run.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:35:59 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 15:25:23 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static int	exe_run_subshell(struct s_shell *sh, struct s_node *sub)
{
	int	pid;
	int	st;

	pid = fork();
	if (pid == -1)
		return (err_per(1, "subshell"));
	if (pid == 0)
	{
		st = sh_run_node(sh, sub);
		sh_cleanup(sh);
		exit(st);
	}
	waitpid(pid, &st, 0);
	return (wstatus(st));
}

static int	exe_run_and_or(struct s_shell *sh,
	struct s_node *left, int op, struct s_node *right)
{
	int	st;

	st = sh_run_node(sh, left);
	if (st == 0 && op == AO_AND)
		return (sh_run_node(sh, right));
	if (st != 0 && op == AO_OR)
		return (sh_run_node(sh, right));
	return (st);
}

int	sh_run_node(struct s_shell *sh, struct s_node *node)
{
	// ast_print(sh, node);
	if (node->kind == N_SIMPLE)
		return (exe_run_simple(sh, &node->u.s_simple));
	else if (node->kind == N_SUBSHELL)
		return (exe_run_subshell(sh, node->u.s_subshell.list));
	else if (node->kind == N_PIPELINE)
		return (exe_run_pipeline(sh, node->u.s_pipeline.v, node->u.s_pipeline.n));
	else if (node->kind == N_ANDOR)
		return (exe_run_and_or(sh, node->u.s_andor.lhs,
			node->u.s_andor.op, node->u.s_andor.rhs));
	return (1);
}
