/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 18:56:49 by echatela          #+#    #+#             */
/*   Updated: 2025/10/19 13:47:10 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_par.h"
#include "sh_exe.h"
#include "sh_exp.h"

static int	capture_line_loop(struct s_shell *sh,
	struct s_redir *redir, int q_del)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (g_sigstate == SIGINT || !line || ft_strcmp(redir->arg, line) == 0)
		{
			(close_set(&redir->fd[0]), close_set(&redir->fd[1]), sh_cleanup(sh));
			if (!line && g_sigstate != SIGINT)
				err_msg(2, "warning", "here-document delimited by end-of-file");
			if (line)
				free(line);
			if (g_sigstate == SIGINT)
				exit(128 + SIGINT);
			exit(0);
		}
		if (!q_del && expand_var(sh, &line, 2) != 0)
		{
			(close_set(&redir->fd[0]), close_set(&redir->fd[1]), free(line));
			(sh_cleanup(sh), exit(2));
		}
		write(redir->fd[1], line, ft_strlen(line));
		free(line);
		write(redir->fd[1], "\n", 1);
	}
}

static int	here_doc_capture(struct s_shell *sh,
	struct s_redir *redir)
{
	pid_t	pid;
	int		q_del;
	int		st;
	
	sh_ignore_signal();
	if (pipe(redir->fd) != 0)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		sh_install_signal_mode(1);
		q_del = exp_unquote_str(redir->arg, 0, 0);
		capture_line_loop(sh, redir, q_del);
	}
	close_set(&redir->fd[1]);
	waitpid(pid, &st, 0);
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	else if (WIFSIGNALED(st))
		return (g_sigstate = SIGINT, WTERMSIG(st));
	return (0);
}

static int	hdoc_process_command(struct s_shell *sh,
	struct s_cmd *cmd)
{
	int	st;
	int	i;

	st = 0;
	i = -1;
	if (cmd->redv)
	{
		while (cmd->redv[++i].arg)
		{
			if (cmd->redv[i].type == R_HDOC)
				st = here_doc_capture(sh, &cmd->redv[i]);
			if (st)
			{
				close_set(&cmd->redv[i].fd[0]);
				sh->last_status = st;
				if (st == 1)
					err_per(1, "here document");
				return (1);
			}
		}
	}
	return (0);
}

int	rd_hdoc_process_all(struct s_shell *sh, struct s_node *node)
{
	int	i;

	i = -1;
	if (node->kind == N_SIMPLE)
		if (hdoc_process_command(sh, &node->u.s_simple) != 0)
			return (1);
	if (node->kind == N_SUBSHELL)
		if (rd_hdoc_process_all(sh, node->u.s_subshell.list) != 0)
			return (1);
	if (node->kind == N_PIPELINE)
		while (++i < node->u.s_pipeline.n)
			if (rd_hdoc_process_all(sh, node->u.s_pipeline.v[i]))
				return (1);
	if (node->kind == N_ANDOR)
	{
		if (rd_hdoc_process_all(sh, node->u.s_andor.lhs) != 0)
			return (1);
		if (rd_hdoc_process_all(sh, node->u.s_andor.rhs) != 0)
			return (1);
	}
	return (0);
}
