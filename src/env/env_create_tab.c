/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:10:00 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 10:48:10 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

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
