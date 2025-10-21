/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:44 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 17:00:54 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static int	sh_export_equal_sign(char *var)
{
	int	i;

	i = 0;
	while (var[i])
	{
		if (var[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

static int	sh_export_add(struct s_shell *sh, char *var, char*key, char *val)
{
	struct s_env	*env;
	struct s_env	*new;
	int				equal_sign;

	env = sh->env;
	equal_sign = !sh_export_equal_sign(var);
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			if (equal_sign)
			{
				(free(env->val), free(env->var));
				env->val = val;
				env->var = ft_strjoin(key, val); // pas les bonnes valeurs
				// en plein milieu de ca, peut-etre faire une
				// autre fonction sh_export_update pour ce cas-la,
				// ne pas oublier de ger l'append ("+=")
			}
		}
	}
}

static int	sh_export_var(struct s_shell *sh, char *var)
{
	char			*key;
	char			*val;
	int				equal_sign;

	equal_sign = !sh_export_equal_sign(var);
	if (equal_sign)
	{
		key = ft_strndup(var, ft_strchr(var, '=') -  var);
		if (!key)
			return (2);
		val = ft_strdup(ft_strchr(var, '+') + 1);
		if (!val)
			return (free(key), 2);
	}
	else
	{
		key = ft_strdup(var);
		if (!key)
			return (2);
		val = NULL;
	}
	return (sh_export_add(sh, var, key, val));
}

int	sh_export(struct s_shell *sh, char **argv)
{
	int				i;
	int				status;

	if (!argv[1])
		return(sh_export_no_arg(sh));
	i = 0;
	status = 0;
	while (argv[++i])
		if (!sh_export_scan_arg(argv[i], &status))
			status = sh_export_var(sh, argv);
	return (status);
}
