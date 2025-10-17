/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:30:59 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 10:30:15 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exp.h"

// static void	expand_unquote_cmd(struct s_cmd *cmd)
// {
// 	int	i;

// 	if (cmd->argv)
// 	{
// 		i = -1;
// 		while (cmd->argv[++i])
// 			exp_unquote_str(cmd->argv[i], 0, 0);
// 	}
// 	if (cmd->redv)
// 	{
// 		i = -1;
// 		while (cmd->redv[++i].arg)
// 			exp_unquote_str(cmd->redv[i].arg, 0, 0);
// 	}
// }

static int	expand_variables_cmd(struct s_shell *sh, struct s_cmd *cmd)
{
	int	i;

	if (cmd->argv)
	{
		i = -1;
		while (cmd->argv[++i])
			if (expand_var(sh, &cmd->argv[i], 0) != 0)
				return (1);
	}
	if (cmd->redv)
	{
		i = -1;
		while (cmd->redv[++i].arg)
			if (cmd->redv[i].type != R_HDOC
				&& expand_var(sh, &cmd->redv[i].arg, 1) != 0)
				return (1);
	}
	return (0);
}

// static int	split_arg_cmd(struct s_cmd *cmd)
// {
// 	struct s_vec	arg_vec;
// 	int				i;

// 	vec_init(&arg_vec, sizeof(char *));
// 	if (cmd->argv)
// 	{
// 		i = -1;
// 		while (cmd->argv[++i])
// 			if (split_arg(&arg_vec, cmd->argv[i]))
// 				return (vec_free(&arg_vec, arg_free), 1);
// 		free_tab_str(cmd->argv);
// 		cmd->argv = arg_vec.data;
// 	}
// 	if (cmd->redv)
// 	{
// 		i = -1;
// 		while (cmd->redv[++i].arg)
// 			unblank_str(cmd->redv->arg, 0, 0);
// 	}
// 	return (0);
// }

// static int	expand_wild_card_cmd(struct s_cmd *cmd)
// {
// 	struct s_vec	argv;
// 	int	i;

// 	if (cmd->argv)
// 	{
// 		vec_init(&argv, sizeof(char *));
// 		i = -1;
// 		while (cmd->argv[++i])
// 			if (expand_wc(&cmd->argv[i], &argv) != 0)
// 				return (vec_free(&argv, arg_free), 1);
// 		free_tab_str(cmd->argv);
// 		cmd->argv = argv.data;
// 	}
// 	if (cmd->redv)
// 	{
// 		i = -1;
// 		while (cmd->redv[++i].arg)
// 			if (cmd->redv[i].type != R_HDOC
// 				&& expand_wc(&cmd->redv[i].arg, NULL) != 0)
// 				return (1);
// 	}
// 	return (0);
// }

int	expand_command(struct s_shell *sh, struct s_cmd *cmd)
{
	(void)sh;
	if (expand_variables_cmd(sh, cmd) != 0)
		return (1);
	// if (split_arg_cmd(cmd) != 0)
	// 	return (1);
	// if (expand_wild_card_cmd(cmd) != 0)
	// 	return (1);
	// expand_unquote_cmd(cmd);
	return (0);
}
