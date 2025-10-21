/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:41:46 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/20 14:40:45 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static int	env_is_var(char *var)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (var[i])
	{
		if (var[i] == '=')
			check = 1;
		i++;
	}
	if (check == 0)
		return (-1);
	else
		return (0);
}

static void	env_key_val(struct s_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env->var[i] && env->var[i] != '=')
	{
		env->key[j] = env->var[i];
		i++;
		j++;
	}
	env->key[j] = 0;
	i++;
	j = 0;
	while (env->var[i])
	{
		env->val[j] = env->var[i];
		i++;
		j++;
	}
	env->val[j] = 0;
	env->in_out = ENV_IN;
}

static int	env_before_equal_sign(char *var)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (var[i] && var[i] != '=')
	{
		i++;
		size++;
	}
	return (size);
}

static int	env_after_equal_sign(char *var)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (var[i] && var[i] != '=')
		i++;
	if (var[i] == '=')
		i++;
	while (var[i])
	{
		i++;
		size++;
	}
	return (size);
}

int	env_new(char *var, struct s_env **result)
{
	int		i;
	struct s_env	*env;

	if (env_is_var(var) != 0)
		return (1);
	env = malloc(sizeof(struct s_env));
	if (!env)
		return (1);
	env->var = malloc(ft_strlen(var) + 1);
	if (!env->var)
		return (env_free(&env), 1);
	i = -1;
	while (var[++i])
		env->var[i] = var[i];
	env->var[i] = '\0';
	env->key = malloc(env_before_equal_sign(var) + 1);
	if (!env->key)
		return (env_free(&env), 1);
	env->val = malloc(env_after_equal_sign(var) + 1);
	if (!env->val)
		return (env_free(&env), 1);
	env_key_val(env);
	env->next = NULL;
	*result = env;
	return (0);
}
