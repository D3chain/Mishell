/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 12:13:53 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 16:06:26 by garivoir         ###   ########.fr       */
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

char	*env_getval(struct s_env *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->val);
		env = env->next;
	}
	return (NULL);
}

//TODO: malloc buf
void	env_change_val(struct s_env **env)
{
	int		i;
	char	*new_val;
	char	buf[4096];

	i = 0;
	ft_bzero(buf, 4096);
	getcwd(buf, 4096);
	new_val = ft_strdup(buf);
	return (0);
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
