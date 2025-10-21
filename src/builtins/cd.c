/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:38 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 15:35:38 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

int	sh_cd(struct s_shell *sh, char **argv)
{
	char	*cwd;
	char	*path;

	if (!argv[1])
	{
		path = env_get_val(sh->env, "HOME");
		if (!path)
			return (write(2, "minishell: cd: HOME not set\n", 28), 1);
	}
	else
		path = argv[1];
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (perror(""), 1);
	if (chdir(path) == -1)
	{
		write(2, "minishell: cd: ", 16);
		write(2, path, ft_strlen(path));
		write(2, ": ", 2);
		perror("");
		return (1);
	}
	(env_change_var(sh, "PWD", path), env_change_var(sh, "OLDPWD", cwd));
	free(cwd);
	return (0);
}
