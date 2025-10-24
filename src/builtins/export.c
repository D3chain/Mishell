/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:44 by echatela          #+#    #+#             */
/*   Updated: 2025/10/23 16:49:46 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_bui.h"
#include "sh_env.h"

static int	sh_export_add(struct s_shell *sh, char *argv)
{
	struct s_env	*env;
	struct s_env	*new;

	env = sh->env;
	if (!env)
	{
		if (env_new(argv, &new) != 0)
			return (2);
		sh->env = new;
		return (0);
	}
	while (env && env->next)
		env = env->next;
	if (env_new(argv, &env->next) != 0)
		return (2);
	return (0);
}

static int	sh_export_append_util(struct s_env *env, char *argv)
{
	char			*tmp_val;

	tmp_val = ft_strdup(env->val);
	if (!tmp_val)
		return (2);
	free(env->val);
	env->val = ft_strjoin(tmp_val, argv);
	if (!env->val)
		return (free(tmp_val), 2);
	return (free(tmp_val), sh_export_new_var(env));
}

static int	sh_export_append(struct s_shell *sh, char *argv)
{
	int				i;
	char			*key;
	struct s_env	*env;

	i = 0;
	env = sh->env;
	key = sh_export_key(argv);
	if (!key)
		return (2);
	env = sh_export_env_key(sh, key);
	if (!env)
		return (free(key), sh_export_add(sh, argv));
	while (argv[i] && !(argv[i] == '+' && argv[i + 1] == '='))
		i++;
	if (!argv[i])
		return (free(key), env->in_out = ENV_IN, 0);
	i += 2;
	if (!env->val || (env->val && !env->val[0]))
	{
		env->val = ft_strdup(&argv[i]);
		if (!env->val)
			return (free(key), 2);
		return (free(key), sh_export_new_var(env));
	}
	return (free(key), sh_export_append_util(env, &argv[i]));
}

static int	sh_export_update(struct s_shell *sh, char *argv)
{
	int				i;
	char			*key;
	struct s_env	*env;

	i = 0;
	env = sh->env;
	key = sh_export_key(argv);
	if (!key)
		return (2);
	env = sh_export_env_key(sh, key);
	if (!env)
		return (free(key), sh_export_add(sh, argv));
	while (argv[i] && argv[i] != '=')
		i++;
	free(env->val);
	if (!argv[i])
		return (env->val = NULL, free(key), sh_export_new_var(env));
	i++;
	env->val = ft_strdup(&argv[i]);
	if (!env->val)
		return (free(key), 2);
	return (free(key), sh_export_new_var(env));
}

int	sh_export(struct s_shell *sh, char **argv)
{
	int				i;
	int				status;
	int				export_type;

	if (!argv[1])
		return (sh_export_no_arg(sh));
	i = 0;
	status = 0;
	while (argv[++i])
	{
		export_type = sh_export_scan_arg(sh, argv[i]);
		if (export_type == EXP_NO)
			status = 1;
		else if (export_type == EXP_MALLOC_ERR)
			status = 2;
		else if (export_type == EXP_ADD)
			status = sh_export_add(sh, argv[i]);
		else if (export_type == EXP_UPDATE)
			status = sh_export_update(sh, argv[i]);
		else if (export_type == EXP_APPEND)
			status = sh_export_append(sh, argv[i]);
	}
	return (status);
}
