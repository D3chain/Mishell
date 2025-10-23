/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:50 by echatela          #+#    #+#             */
/*   Updated: 2025/10/23 22:42:11 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static void	sh_unset_util(struct s_env *env,
	struct s_env *tmp_env, struct s_env *tmp_prev, struct s_env *tmp_next)
{
	if (tmp_prev)
		tmp_prev->next = tmp_next;
	else
		env = tmp_next;
	env_free(&tmp_env);
}

static void	sh_unset_start(struct s_env *env,
	struct s_env *tmp_env, struct s_env *tmp_prev)
{
	tmp_env = env;
	tmp_prev = NULL;
}

static void	sh_unset_end(struct s_env *tmp_env,
	struct s_env *tmp_prev, struct s_env *tmp_next)
{
	tmp_prev = tmp_env;
	tmp_env = tmp_next;
}

int	sh_unset(struct s_shell *sh, char **argv)
{
	int	i;

	struct s_env *(env) = NULL;
	struct s_env *(tmp_env) = NULL;
	struct s_env *(tmp_prev) = NULL;
	struct s_env *(tmp_next) = NULL;
	if (!argv[1] || (argv[1] && !argv[1][0]))
		return (0);
	i = 0;
	env = sh->env;
	while (argv[++i])
	{
		sh_unset_start(env, tmp_env, tmp_prev);
		while (tmp_env)
		{
			tmp_next = tmp_env->next;
			if (ft_strcmp(tmp_env->key, argv[i]) == 0)
			{
				sh_unset_util(env, tmp_env, tmp_prev, tmp_next);
				break ;
			}
			sh_unset_end(tmp_env, tmp_prev, tmp_next);
		}
	}
	return (sh->env = env, 0);
}
