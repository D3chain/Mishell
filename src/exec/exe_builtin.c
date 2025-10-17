/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:59:01 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 17:00:55 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static int	std_keep_fds(int std_fds[2])
{
	std_fds[0] = dup(STDIN_FILENO);
	if (std_fds[0] == -1)
		return (1);
	std_fds[1] = dup(STDOUT_FILENO);
	if (std_fds[1] == -1)
		return (close(std_fds[0]), 1);
	return (0);
}

static int	std_reset_fds(int std_fds[2])
{
	if (dup2(STDIN_FILENO, std_fds[0]) != 0)
		return (close(std_fds[0]), close(std_fds[1]), 1);
	if (dup2(STDOUT_FILENO, std_fds[1]) != 0)
		return (close(std_fds[0]), close(std_fds[1]), 1);
	(close(std_fds[0]), close(std_fds[1]));
	return (0);
}

int	is_builtin(char *cmd)
{
	int			i;
	const char	*built_in[9] = {NULL,
		"cd", "echo", "env", "exit", "export", "pwd", "unset", NULL};

	i = 0;
	while (built_in[++i])
		if (ft_strcmp(cmd, built_in[i]) == 0)
			return (i);
	return (0);
}

int	exec_builtin(struct s_shell *sh, int std_fds[2], char **argv)
{
	int	st;
	int	(*bi_fn[])(struct s_shell*, char**)
		= {NULL, sh_cd, sh_echo, sh_env,
			sh_exit, sh_export, sh_pwd, sh_unset, NULL};

	if (ft_strcmp(argv[0], "exit") == 0)
	{
		(close(std_fds[0]), close(std_fds[1]));
		return (sh_exit(sh, argv));
	}
	st = bi_fn[is_builtin(argv[0])](sh, argv);
	std_reset_fds(std_fds);
	return (st);
}

int	run_builtin(struct s_shell *sh, struct s_cmd *cmd)
{
	int	st;
	int	std_fds[2];

	if (std_keep_fds(std_fds) != 0)
		return (1);
	st = redir_apply(cmd->redv);
	if (st != 0)
		(sh_cleanup(sh), exit(st));
	st = exec_builtin(sh, std_fds, cmd->argv);
	return (st);
}