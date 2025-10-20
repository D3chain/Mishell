/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:36:20 by echatela          #+#    #+#             */
/*   Updated: 2025/10/20 11:31:52 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static void	close_hd_from(struct s_redir *redv, int i)
{
	while (redv[++i].arg)
		if (redv[i].type == R_HDOC)
			close_set(&redv[i].fd[0]);
}

static int	open_out(int type, char *file, int *p_fd_out)
{
	int	flags;

	if (*p_fd_out != -1)
		close_set(p_fd_out);
	if (type == R_OUT)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (type == R_APP)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	*p_fd_out = open(file, flags, 0644);
	if (*p_fd_out == -1)
		return (err_per(1, file));
	return (0);
}

static int	open_in(int type, char *file, int red_fd[2], int *p_fd_in)
{
	if (*p_fd_in != -1)
		close_set(p_fd_in);
	if (type == R_IN)
	{
		*p_fd_in = open(file, O_RDONLY);
		if (*p_fd_in == -1)
			return (err_per(1, file));
	}
	if (type == R_HDOC)
		*p_fd_in = red_fd[0];
	return (0);
}

static int	dup_redirs(int final_fds[2])
{
	if ((final_fds[0] != -1 && dup2(final_fds[0], STDIN_FILENO) == -1)
		|| (final_fds[1] != -1 && dup2(final_fds[1], STDOUT_FILENO) == -1))
	{
		close_set(&final_fds[0]);
		close_set(&final_fds[1]);
		return (err_per(2, "redir"));
	}
	close_set(&final_fds[0]);
	close_set(&final_fds[1]);
	return (0);
}

int	redir_apply(struct s_redir *redv)
{
	int	i;
	int	final_fds[2];
	int	st;
	
	if (!redv)
		return (0);
	final_fds[0] = -1;
	final_fds[1] = -1;
	i = -1;
	while (redv[++i].arg)
	{
		if (redv[i].type == R_IN || redv[i].type == R_HDOC)
			st = open_in(redv[i].type, redv[i].arg, redv[i].fd, &final_fds[0]);
		else if (redv[i].type == R_OUT || redv[i].type == R_APP)
			st = open_out(redv[i].type, redv[i].arg, &final_fds[1]);
		if (st != 0)
		{
			close_set(&final_fds[0]);
			close_set(&final_fds[1]);
			close_hd_from(redv, i);
			return (st);
		}
	}
	return (dup_redirs(final_fds));
}
