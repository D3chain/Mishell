/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:29:18 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 16:51:57 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exp.h"
#include "sh_exe.h"

int	exe_run_simple(struct s_shell *sh, struct s_cmd *cmd)
{
	int	st;
	int	pid;

	if (expand_command(sh, cmd) != 0)
		return (2);
	if (is_builtin(cmd->argv[0]))
		return (run_builtin(sh, cmd));
	pid = fork();
	if (pid == -1)
		return (err_per(1, "exec"));
	if (pid == 0)
	{
		child_install_signal(0);
		st = redir_apply(cmd->redv);
		if (st != 0)
			(sh_cleanup(sh), exit(st));
		exec_command(sh, cmd->argv);
	}
	sh_ignore_signal();
	waitpid(pid, &st, 0);
	return (wstatus(st));
}
