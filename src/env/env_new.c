/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:41:46 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/15 16:51:41 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* New "env"					*/
/* struct creation file			*/
/*------------------------------*/

#include "shell.h"
#include "sh_env.h"

/*------------------------------*/
/* Check if there is			*/
/* an '=' sign on the variable	*/
/*------------------------------*/
static int	env_check_var(char *var)
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

/*------------------------------*/
/* Put name and value			*/
/* of each "env" variable		*/
/* into two separate variables	*/
/*------------------------------*/
void	env_var_name_value(struct s_env *env)
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
	// env->in_or_out = IN;
}

/*------------------------------*/
/* Create a new					*/
/* "env" structure				*/
/*------------------------------*/
int	env_new(char *var, struct s_env **result)
{
	int		i;
	struct s_env	*env;

	if (env_check_var(var) != 0)
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
	env_var_name_value(env);
	env->next = NULL;
	*result = env;
	return (0);
}
