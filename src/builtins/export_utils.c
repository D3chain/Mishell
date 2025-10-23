/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:35:33 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/23 16:36:05 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_bui.h"
#include "sh_env.h"

char	*sh_export_key(char *argv)
{
	int		i;
	char	*key;

	i = 0;
	while (argv[i] && argv[i] != '='
		&& !(argv[i] == '+' && argv[i + 1] == '='))
		i++;
	key = ft_strndup(argv, i);
	if (!key)
		return (NULL);
	return (key);
}

struct s_env	*sh_export_env_key(struct s_shell *sh, char *key)
{
	struct s_env	*env;

	env = sh->env;
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		env = env->next;
	}
	return (NULL);
}

int	sh_export_new_var(struct s_env *env)
{
	char	*tmp_var;

	if (!env->val)
	{
		free(env->var);
		env->var = ft_strjoin(env->key, "=");
		if (!env->var)
			return (2);
		return (env->in_out = ENV_IN, 0);
	}
	tmp_var = ft_strjoin(env->key, "=");
	if (!tmp_var)
		return (2);
	free(env->var);
	env->var = ft_strjoin(tmp_var, env->val);
	if (!env->var)
		return (free(tmp_var), 2);
	free(tmp_var);
	env->in_out = ENV_IN;
	return (0);
}
