/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:13:53 by echatela          #+#    #+#             */
/*   Updated: 2025/10/20 19:43:41 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

void	env_free(struct s_env **env)
{
	if (!env || !*env)
		return ;
	if ((*env)->var)
		free((*env)->var);
	if ((*env)->key)
		free((*env)->key);
	if ((*env)->val)
		free((*env)->val);
	free(*env);
	*env = NULL;
	return ;
}

char	*env_get_val(struct s_env *env, char *key)
{
	struct s_env	*tmp_env;
	
	tmp_env = env;
	while (env)
	{
		if (ft_strcmp(tmp_env->key, key) == 0)
			return (tmp_env->val);
		tmp_env = tmp_env->next;
	}
	return (NULL);
}

int	env_change_var(struct s_shell *sh, char *key, char *new_val)
{
	char			*buf;
	struct s_env	*env = sh->env;

	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			buf = ft_strjoin(key, "=");
			if (!buf)
				return (2);
			env->var = ft_strjoin(buf, new_val);
			if (!env->var)
				return (free(buf), 2);
			free(env->val);
			env->val = ft_strdup(new_val);
			if (!env->val)
				return (free(buf), 2);
			free(buf);
			return (0);
		}
		env = env->next;
	}
	return (1);
}


char	**env_create_tab(struct s_env *env)
{
	struct s_env	*cur;
	char			**env_tab;
	int				i;

	i = 0;
	cur = env;
	while (cur)
		(cur = cur->next, i++);
	env_tab = malloc(sizeof(char *) * (i + 1));
	if (!env_tab)
		return (NULL);
	i = 0;
	while (env)
		(env_tab[i++] = env->var, env = env->next);
	env_tab[i] = NULL;
	return (env_tab);
}
