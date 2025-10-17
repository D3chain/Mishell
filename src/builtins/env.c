/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:40 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 16:49:10 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* env built-in					*/
/*------------------------------*/

#include "shell.h"

/*------------------------------*/
/* minishell env				*/
/* built-in main function		*/
/*------------------------------*/
// int	ms_env(char **cmd, struct s_env *envp, int last_st)
// {
// 	if (!cmd || !cmd[0])
// 		return (1);	//error
// 	if (ft_strcmp(cmd[0], "env") != 0)
// 		return (1);	//error
// 	if (!envp)
// 		return (0);
// 	while (envp)
// 	{
// 		if (envp->var)
// 			printf("%s\n", envp->var);
// 		envp = envp->next;
// 	}
// 	return (0);
// }

int	sh_env(struct s_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}
