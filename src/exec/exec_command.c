/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:22:25 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 15:18:35 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static char	*get_path_val(struct s_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->key, "PATH") == 0)
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

int	exec_command(struct s_shell *sh, char **argv)
{
	char	**env;
	char	*path;
	int		st;

	if (!argv || !argv[0])
		(sh_cleanup(sh), exit(0));
	st = find_valid_path(&path, get_path_val(sh->env), argv[0]);
	if (st != 0)
		(err_cmd(st, argv[0]), sh_cleanup(sh), exit(st));
	env = env_create_tab(sh->env);
	if (!env)
		(free(path), sh_cleanup(sh), exit(err_per(2, "env")));
	execve(path, argv, env);
	free(path);
	err_per(1, argv[0]);
	sh_cleanup(sh);
	exit(exit_code_errno(errno));
}
