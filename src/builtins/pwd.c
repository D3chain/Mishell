/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:47 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 15:36:45 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

int	sh_pwd(struct s_shell *sh, char **argv)
{
	char	*cwd;

	(void)sh;
	if (argv[1])
	{
		if (argv[1][0])
		{
			if (argv[1][0] == '-')
			{
				write(2, "minishell: pwd: ", 16);
				write(2, argv[1], ft_strlen(argv[1]));
				write(2, ": invalid option\npwd: usage: pwd [-LP]\n", 39);
				return (1);
			}
		}
	}
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		write(2, "minishell: pwd: error retrieving current directory: ", 52);
		write(2, "getcwd: cannot access parent directories: ", 42);
		write(2, "No such file or directory\n", 26);
		return (1);
	}
	return (printf("%s\n", cwd), free(cwd), 0);
}
