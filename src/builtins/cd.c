/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:38 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 16:49:25 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* cd built-in					*/
/*------------------------------*/

#include "shell.h"

/*------------------------------*/
/* Finding HOME path			*/
/* from envp main variable		*/
/*------------------------------*/
// static char	*ms_cd_home_path(struct s_env *envp)
// {
// 	char	*home;
// 	struct s_env	*envp_temp;

// 	if (!envp)
// 		return (NULL);
// 	envp_temp = envp;
// 	while (envp_temp)
// 	{
// 		if (ft_strncmp(envp_temp->var, "HOME=", 5) == 0)
// 		{
// 			home = ft_strdup(&envp_temp->var[5]);
// 			if (!home)
// 				return (NULL);	//error
// 			return (home);
// 		}
// 		envp_temp = envp_temp->next;
// 	}
// 	return (NULL);
// }

/*------------------------------*/
/* minishell cd					*/
/* built-in main function		*/
/*------------------------------*/
// int	sh_cd(char **cmd, struct s_env *envp, int last_st)
// {
// 	int		cd;
// 	char	*home;

// 	if (!cmd || !cmd[0])
// 		return (-1);		//error
// 	if (cmd[0] && cmd[1] && cmd[2])
// 		return (-1);		//error
// 	if (!envp)
// 		return (-1);		//error
// 	if (ft_strcmp(cmd[0], "cd") != 0)
// 		return (-1);		//error
// 	if (!cmd[1])
// 	{
// 		home = ms_cd_home_path(envp);
// 		if (!home)
// 			return (-1);	//error
// 		cd = chdir(home);
// 		free(home);
// 		return (cd);
// 	}
// 	cd = chdir(cmd[1]);
// 	return (cd);
// }

int	sh_cd(struct s_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}
