/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:28:47 by echatela          #+#    #+#             */
/*   Updated: 2025/10/15 17:35:37 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"
#include "sh_bui.h"

static int	redir_pipe(int prev_read, int *pipe_fd, int i, int n)
{
	if (i > 0)
	{
		if (dup2(prev_read, STDIN_FILENO) != 0)
			return (close(prev_read), 1);
		close (prev_read);
	}
	close(pipe_fd[0]);
	if (i < n - 1)
		if (dup2(pipe_fd[1], STDOUT_FILENO) != 0)
			return (close(pipe_fd[1]), 1);
	close(pipe_fd[1]);
	return (0);
}

static int	wait_children(int n, int last_pid)
{
	int	pid;
	int	st;
	int	last_st;

	while (n--)
	{
		pid = wait(&st);
		if (pid == last_pid)
			last_st = st;
	}
	return (wstatus(last_st));
}

static int	run_simple_pipe(struct s_shell *sh, struct s_node *node)
{
	if (node->kind == N_SIMPLE)
	{
		redir_apply(node->u.s_simple.redv);
		// if (is_builtin(node->u.s_simple.argv[0]))
		// 	exec_builtin(sh, node->u.s_simple.argv);
		// else
		exec_command(sh, node->u.s_simple.argv);
	}
	// else if (node->kind == N_SUBSHELL)
	// 	exe_run_subshell(sh, node->u.s_subshell.list);
	sh_cleanup(sh);
	exit(0);
}

int	exe_run_pipeline(struct s_shell *sh, struct s_node **cmdv, int n)
{
	int	i;
	int	prev_read;
	int	pipe_fd[2];
	int	pid;

	i = -1;
	while (++i < n)
	{
		if (pipe(pipe_fd) != 0)
			return (1);
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			if (redir_pipe(prev_read, pipe_fd, i, n) != 0)
				(sh_cleanup(sh), exit(1));
			run_simple_pipe(sh, cmdv[i]);
		}
		if (i < n - 1)
			prev_read = dup(pipe_fd[0]);
		(close(pipe_fd[0]), close(pipe_fd[1]));
	}
	sh->last_status = wait_children(n, pid);
	return (sh->last_status);
}
