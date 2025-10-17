/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:27:29 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/15 16:29:57 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* New "env"					*/
/* struct creation file			*/
/*------------------------------*/

#include "shell.h"
#include "sh_env.h"

/*------------------------------*/
/* Free "env" structure			*/
/*------------------------------*/
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

/*------------------------------*/
/* Check where the '=' sign		*/
/* is located, to allocate good	*/
/* memory size to each variable	*/
/*------------------------------*/
int	env_before_equal_sign(char *var)
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

int	env_after_equal_sign(char *var)
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
