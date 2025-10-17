/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:47 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 16:48:09 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* pwd built-in					*/
/*------------------------------*/

#include "shell.h"

/*------------------------------*/
/* minishell pwd				*/
/* built-in main function		*/
/*------------------------------*/
// int	ms_pwd(char **cmd, struct s_env *envp, int last_st)
// {
// 	char	*buf;

// 	(void)last_st;
// 	(void)envp;
// 	(void)cmd;
// 	buf = NULL;
// 	buf = getcwd(buf, 4096);
// 	if (!buf)
// 		return (-1);	//error
// 	printf("%s\n", buf);
// 	free(buf);
// 	return (0);
// }

int	sh_pwd(struct s_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}
