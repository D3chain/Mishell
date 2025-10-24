/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:38 by echatela          #+#    #+#             */
/*   Updated: 2025/10/24 13:45:02 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static int	sh_cd_path_error(char *path, char *cwd)
{
	write(2, "minishell: cd: ", 16);
	write(2, path, ft_strlen(path));
	write(2, ": ", 2);
	perror("");
	if (cwd)
		free(cwd);
	return (1);
}

static int	sh_cd_no_arg(struct s_shell *sh)
{
	char			*cwd;
	char			*path;
	struct s_env	*env;
	
	path = env_get_val(sh->env, "HOME");
	if (!path)
		return (write(2, "minishell: cd: HOME not set\n", 28), 1);
	env = sh->env;
	while (env)
	{
		if (ft_strcmp(env->key, "PWD") == 0)
			break;
		env = env->next;
	}
	cwd = ft_strdup(env->val);
	if (!cwd)
		return (2);
	if (chdir(path) != 0)
		return (sh_cd_path_error(path, cwd));
	if (cwd)
		(env_change_var(sh, "OLDPWD", cwd), free(cwd));
	env_change_var(sh, "PWD", path);
	return (0);
}

int	sh_cd(struct s_shell *sh, char **argv)
{
	char	*cwd;
	char	*path;

	if (!argv[1])
		return (sh_cd_no_arg(sh));
	path = argv[1];
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (perror(""), 1);
	if (chdir(path) != 0)
		return (sh_cd_path_error(path, cwd));
	if (cwd)
		(env_change_var(sh, "OLDPWD", cwd), free(cwd));
	env_change_var(sh, "PWD", path);
	return (0);
}
