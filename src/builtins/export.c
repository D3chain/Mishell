/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:44 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 16:48:49 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*------------------------------*/
/* export built-in				*/
/*------------------------------*/

#include "shell.h"

// rajouter une fonction qui permet d'ajouter a l'env meme les variables
// sans valeur, et rajouter a la struct t_env si la variable doit ou non
// etre affichee dans l'environnement

// puis rajouter aussi une fonction qui permet d'append une variable (var+=a)

/*------------------------------*/
/* Print "envp" variable		*/
/*------------------------------*/
// static void	ms_export_print_env(struct s_env *env)
// {
// 	while (env->next)
// 	{
// 		printf("declare -x %s=\"%s\"\n", env->key, env->val);
// 		env = env->next;
// 	}
// }

/*------------------------------*/
/* Make bubble sort by			*/
/* alphabatcical order for		*/
/* "env", then print variable	*/
/*------------------------------*/
// static void	ms_export_bubble_sort(struct s_env *env)
// {
// 	struct s_env	*temp;

// 	while (env && env->next)
// 	{
// 		if (ft_strcmp(env->key, env->next->key) > 0)
// 		{
// 			env->next->next = env->next;
// 		}
// 		else
// 			temp = temp->next;
// 	}
// 	ms_export_print_env(temp);
// }

/*------------------------------*/
/* Sort "env" chained list		*/
/* by alphabetical order, and	*/
/* display variables on screen	*/
/*------------------------------*/
// static int	ms_export_alphabetical(struct s_env *env)
// {
// 	if (!env || !env->var)
// 		return (-1);	//error
// 	if (!env->next)
// 	{
// 		ms_export_print_env(env);
// 		return (0);
// 	}
// 	ms_export_bubble_sort(env);
// 	return (0);
// }

/*------------------------------*/
/* minishell export				*/
/* built-in main function		*/
/*------------------------------*/
// int	ms_export(char **cmd, struct s_env *env, int last_st)
// {
// 	int	i;
// 	struct s_env	*result;
	
// 	if (!cmd || !cmd[0])
// 		return (-1);	//error
// 	if (ft_strcmp(cmd[0], "export") != 0)
// 		return (-1);	//error
// 	if (env == NULL)
// 		return (-1);	//error
// 	if (!cmd[1])
// 		return(ms_export_alphabetical(env));
// 	while (env->next)
// 		env = env->next;
// 	i = 1;
// 	while (cmd[i])
// 	{
// 		env_new(cmd[i], sh, &result);
// 		if (!result)
// 			return (-1);	//error
// 		env->next = result;
// 		env->next->next = NULL;
// 		i++;
// 	}
// 	return (0);
// }

int	sh_export(struct s_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}
