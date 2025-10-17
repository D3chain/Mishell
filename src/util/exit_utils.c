/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:25 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 12:05:03 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

int	wstatus(int st)
{
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	if (WIFSIGNALED(st))
	{
		if (WTERMSIG(st) == SIGINT)
			return (write(2, "\n", 1), 130);
		if (WTERMSIG(st) == SIGQUIT)
			return (write(2, "Quit (core dumped)\n", 20), 131);
	}
	return (1);
}

int	exit_code_errno(int err)
{
	if (err == ENOENT)
		return (127);
	if (err == EACCES || err == EISDIR || err == ENOTDIR)
		return (126);
	return (1);
}
