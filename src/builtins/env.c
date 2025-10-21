/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:40 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 15:35:53 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

int	sh_env(struct s_shell *sh, char **argv)
{
	struct s_env	*tmp_env;

	if (argv[1])
	{
		write(2, "minishell: env: ", 16);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory\n", 28);
		return (127);
	}
	tmp_env = sh->env;
	while (tmp_env)
	{
		if (tmp_env->in_out == ENV_IN && tmp_env->var)
			printf("%s\n", tmp_env->var);
		tmp_env = tmp_env->next;
	}
	return (0);
}
