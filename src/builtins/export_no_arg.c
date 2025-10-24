/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:45:03 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/23 16:58:56 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static void	sh_export_no_arg_print(struct s_env **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		printf("export %s", tab[i]->key);
		if (tab[i]->in_out == ENV_IN)
			printf("=\"%s\"", tab[i]->val);
		printf("\n");
		i++;
	}
	return ;
}

static void	sh_export_no_arg_util(struct s_shell *sh, struct s_env **tab, int i)
{
	int				j;
	struct s_env	*tmp;

	j = -1;
	while (++j < env_size(sh->env) - i - 1)
	{
		if (ft_strcmp(tab[j]->key, tab[j + 1]->key) > 0)
		{
			tmp = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = tmp;
		}
	}
}

int	sh_export_no_arg(struct s_shell *sh)
{
	int				i;
	struct s_env	*env;
	struct s_env	**tab;

	if (!env_size(sh->env))
		return (0);
	tab = malloc(sizeof(struct s_env *) * (env_size(sh->env) + 1));
	if (!tab)
		return (2);
	i = 0;
	env = sh->env;
	while (env)
	{
		tab[i++] = env;
		env = env->next;
	}
	tab[i] = NULL;
	i = -1;
	while (++i < env_size(sh->env) - 1)
		sh_export_no_arg_util(sh, tab, i);
	return (sh_export_no_arg_print(tab), free(tab), 0);
}
