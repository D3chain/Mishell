/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:52:49 by echatela          #+#    #+#             */
/*   Updated: 2025/10/19 12:30:30 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static void	close_hd_from(struct s_redir *redv, int i)
{
	while (redv[++i].arg)
		if (redv[i].type == R_HDOC)
			close(redv[i].fd[0]);
}

static int	redir_in(struct s_redir *redv, int type)
{
	if (type == R_IN)
	{
		redv->fd[0] = open(redv->arg, O_RDONLY);
		if (redv->fd[0] < 0)
			return (err_per(2, "redir"));
	}
	if (dup2(redv->fd[0], STDIN_FILENO) == -1)
	{
		close(redv->fd[0]);
		return (err_per(2, "redir"));
	}
	close(redv->fd[0]);
	return (0);
}

static int	redir_out(struct s_redir *redv, int type)
{
	int	flags;

	if (type == R_OUT)
		flags = O_WRONLY | O_CREAT | O_TRUNC;
	if (type == R_APP)
		flags = O_WRONLY | O_CREAT | O_APPEND;
	redv->fd[1] = open(redv->arg, flags, 0644);
	if (redv->fd[1] < 0)
		return (err_per(2, "redir"));
	if (dup2(redv->fd[1], STDOUT_FILENO) == -1)
	{
		close(redv->fd[1]);
		return (err_per(2, "redir"));
	}
	close(redv->fd[1]);
	return (0);
}

int	redir_apply(struct s_redir *redv)
{
	int	st;
	int	i;

	if (!redv)
		return (0);
	i = -1;
	while (redv[++i].arg)
	{
		if (redv[i].type == R_IN || redv[i].type == R_HDOC)
			st = redir_in(redv, redv[i].type);
		if (redv[i].type == R_OUT || redv[i].type == R_APP)
			st = redir_out(redv, redv[i].type);
		printf("caca\n");
		if (st != 0)
			return (close_hd_from(redv, i), st);
	}
	return (0);
}
