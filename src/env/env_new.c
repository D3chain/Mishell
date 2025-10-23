/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:41:46 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/23 16:22:23 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static int	env_new_in_or_out(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (ENV_IN);
		i++;
	}
	return (ENV_OUT);
}

static char	*env_new_var(char *var)
{
	int		i;
	int		j;
	int		scan;
	char	*new_var;

	new_var = malloc(ft_strlen(var) + 1);
	if (!new_var)
		return (NULL);
	i = 0;
	j = 0;
	scan = 0;
	while (var[i])
	{
		if (scan == 0 && i > 1 && var[i] == '=')
		{
			scan = 1;
			if (var[i - 1] == '+')
				j--;
		}
		new_var[j] = var[i];
		i++;
		j++;
	}
	new_var[j] = 0;
	return (new_var);
}

static void	env_new_equal(struct s_env **env, char *equal, char *var, int i)
{
	int	key_len;

	if (i == 0)
	{
		key_len = equal - var;
		(*env)->key = ft_strndup(var, key_len);
		if (!(*env)->key)
			return ;
		(*env)->val = ft_strdup(equal + 1);
		if (!(*env)->val)
			return ;
	}
	if (i == 1)
	{
		(*env)->key = ft_strdup(var);
		if (!(*env)->key)
			return ;
		(*env)->val = NULL;
	}
}

static struct s_env	*env_new_struct(void)
{
	struct s_env	*env;

	env = malloc(sizeof(struct s_env));
	if (!env)
		return (NULL);
	env->val = NULL;
	env->key = NULL;
	env->var = NULL;
	env->next = NULL;
	env->in_out = ENV_IN;
	return (env);
}

int	env_new(char *var, struct s_env **result)
{
	struct s_env	*env;
	int				env_type;
	char			*equal_sign_var;
	char			*new_var;

	env = env_new_struct();
	if (!env)
		return (2);
	new_var = env_new_var(var);
	if (!new_var)
		return (env_free(&env), 2);
	env_type = env_new_in_or_out(new_var);
	env->var = new_var;
	env->in_out = env_type;
	equal_sign_var = ft_strchr(new_var, '=');
	if (equal_sign_var)
		env_new_equal(&env, equal_sign_var, new_var, 0);
	else
		env_new_equal(&env, equal_sign_var, new_var, 1);
	if (!env->key || (equal_sign_var && !env->val))
		return (env_free(&env), 2);
	return (*result = env, 0);
}
