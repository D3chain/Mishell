/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:43:37 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/21 16:44:00 by garivoir         ###   ########.fr       */
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
		if (tab[i]->val)
			printf("=\"%s\"", tab[i]->val);
		printf("\n");
		i++;
	}
	return ;
}

static int	sh_export_no_arg(struct s_shell *sh)
{
	int				i;
	int				j;
	struct s_env	*env;
	struct s_env	*tmp;
	struct s_env	**tab;
	
	if (!env_size(sh->env))
		return (0);
	tab = malloc(sizeof(struct s_env *) * (env_size(sh->env) + 1));
	if (!tab)
		return (2);
	i = 0;
	env = sh->env;
	while (env)
		(tab[i++] = env, env = env->next);
	tab[i] = NULL;
	i = -1;
	while (++i < env_size(sh->env) - 1)
	{
		j = -1;
		while (++j < env_size(sh->env) - i - 1)
			if (ft_strcmp(tab[j]->key, tab[j + 1]->key) > 0)
				(tmp = tab[j], tab[j] = tab[j + 1], tab[j + 1] = tmp);
	}
	return (sh_export_no_arg_print(tab), free(tab), 0);
}

static int	sh_export_scan_arg(char *argv, int *status)
{
	int	i;

	i = 0;
	if (!ft_isalpha(argv[i]) && argv[i] != '_')
	{
		write(2, "minishell: export: '", 20);
		write(2, argv, ft_strlen(argv));
		write(2, "': not a valid identifier\n", 26);
		*status = 1;
		return (1);
	}
	while (argv[i])
	{
		if (!ft_isalnum(argv[i]) && argv[i] != '_' && argv[i] != '=')
		{
			write(2, "minishell: export: '", 20);
			write(2, argv, ft_strlen(argv));
			write(2, "': not a valid identifier\n", 26);
			*status = 1;
			return (1);
		}
		i++;
	}
	return (0);
}
