/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:29:25 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 14:09:41 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

int	wstatus(int st)
{
	if (WIFEXITED(st))
		return (WEXITSTATUS(st));
	if (WIFSIGNALED(st))
		return (WTERMSIG(st) + 128);
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
