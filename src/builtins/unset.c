/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:50 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 13:20:07 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* unset built-in				*/
/*------------------------------*/

#include "shell.h"
#include "sh_env.h"

/*------------------------------*/
/* Delete variable				*/
/* named unset's argument		*/
/*------------------------------*/
// static void	ms_unset_delete_var(struct s_env *env)
// {
// 	struct s_env	*temp1;
// 	struct s_env	*temp2;

// 	temp1 = env;
// 	temp2 = env->next->next;
// 	env_free(&env);
// 	if (!temp1)
// 		env = temp2;
// 	else
// 	{
// 		env = temp1;
// 		env->next = temp2;
// 	}
// }

/*------------------------------*/
/* Create new "envp"			*/
/* after unset built-in			*/
/*------------------------------*/
// static void	ms_unset_new_envp(char *cmd, struct s_env *envp)
// {
// 	if (!envp)
// 		return ;
// 	while (envp->next)
// 	{
// 		if (ft_strcmp(cmd, envp->key) == 0)
// 		{
// 			ms_unset_delete_var(envp);
// 			return ;
// 		}
// 		envp = envp->next;
// 	}
// 	return ;
// }

/*------------------------------*/
/* minishell unset				*/
/* built-in main function		*/
/*------------------------------*/
// int	ms_unset(char **cmd, struct s_env *envp, int last_st)
// {
// 	int	i;

// 	if (!cmd || !cmd[0])
// 		return (-1);	//error
// 	if (ft_strcmp(cmd[0], "unset") != 0)
// 		return (-1);	//error
// 	if (!cmd[1])
// 		return (0);
// 	i = 1;
// 	while (cmd[i])
// 		ms_unset_new_envp(cmd[i++], envp);
// 	return (0);
// }

int	sh_unset(struct s_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}
