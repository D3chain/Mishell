/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:38 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 15:53:38 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	sh_cd_home(struct s_shell *sh)
{
	struct s_env	*tmp;
	
	tmp = sh->env;
	while (sh->env)
	{
		if (ft_strcmp(sh->env->key, "HOME") == 0)
		{
			while (tmp)
			{
				if (ft_strcmp(tmp->key, "OLDPWD") == 0)
				{
					env_change_val(&sh->env);
					break ;
				}
			}
			return (chdir(sh->env->val));
		}
		sh->env = sh->env->next;
	}
	write(2, "bash: cd: HOME not set\n", 23);
	return (1);
}

int	sh_cd(struct s_shell *sh, char **argv)
{
	if (!argv[1])
		return (sh_cd_home(sh));
	return (0);
}
