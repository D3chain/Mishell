/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:32:55 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/15 16:53:52 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* New "env"					*/
/* list creation file			*/
/*------------------------------*/

#include "shell.h"
#include "sh_env.h"

/*------------------------------*/
/* Free "env" list				*/
/*------------------------------*/
void	env_clear_list(struct s_env **env)
{
	struct s_env	*temp;

	temp = NULL;
	if (!env || !*env)
		return ;
	while (*env)
	{
		temp = (*env)->next;
		env_free(env);
		(*env) = temp;
	}
	return ;
}

/*------------------------------*/
/* Create a new "env"			*/
/* variable with a chained list	*/
/*------------------------------*/
int	env_create_list(struct s_shell *sh, char **env_old)
{
	int		i;
	struct s_env	*env;
	struct s_env	*env_temp;

	if (!env_old || !env_old[0])
		return (1);
	if (env_new(env_old[0], &env) != 0)
		return (1);
	if (!env)
		return (1);
	i = 0;
	env_temp = env;
	while (env_old[i])
	{
		env_new(env_old[i], &env->next);
		if (!env->next)
			return (env_clear_list(&env_temp), 1);
		env = env->next;
		i++;
	}
	sh->env = env_temp;
	return (0);
}
