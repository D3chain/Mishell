/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_scan_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:44:46 by garivoir          #+#    #+#             */
/*   Updated: 2025/10/23 22:30:59 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_bui.h"
#include "sh_env.h"

static int	sh_export_scan_arg_not_valid(char *argv)
{
	write(2, "minishell: export: `", 20);
	write(2, argv, ft_strlen(argv));
	write(2, "': not a valid identifier\n", 26);
	return (EXP_NO);
}

static int	sh_export_scan_arg_update(struct s_shell *sh, char *argv, int size)
{
	int				i;
	char			*key;
	struct s_env	*env;

	key = malloc(size + 1);
	if (!key)
		return (EXP_MALLOC_ERR);
	i = 0;
	env = sh->env;
	while (i < size)
	{
		key[i] = argv[i];
		i++;
	}
	key[i] = 0;
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (free(key), 1);
		env = env->next;
	}
	free(key);
	return (0);
}

int	sh_export_scan_arg(struct s_shell *sh, char *argv)
{
	int	i;

	if (!argv[0] || (!ft_isalpha(argv[0]) && argv[0] != '_'))
		return (sh_export_scan_arg_not_valid(argv));
	i = 1;
	while (argv[i] && argv[i] != '=')
	{
		if (argv[i] == '+' && argv[i + 1] == '=')
			return (EXP_APPEND);
		if (!ft_isalnum(argv[i]))
			return (sh_export_scan_arg_not_valid(argv));
		i++;
	}
	if (!argv[i])
	{
		if (sh_export_scan_arg_update(sh, argv, i))
			return (EXP_NO);
		else
			return (EXP_ADD);
	}
	if (sh_export_scan_arg_update(sh, argv, i))
		return (EXP_UPDATE);
	else
		return (EXP_ADD);
	return (EXP_NO);
}
