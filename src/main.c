/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:10:30 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 11:53:17 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

void	sh_cleanup(struct s_shell *sh)
{
	if (sh->env)
	{
		env_clear_list(&sh->env);
		sh->env = NULL;
	}
	if (sh->root)
	{
		free_node(sh->root);
		sh->root = NULL;
	}
}

static int	sh_init(struct s_shell *sh, char **envp)
{
	ft_bzero(sh, sizeof(*sh));
	if (env_create_list(sh, envp) != 0)
		return (1);
	return (0);
}

int main(int ac, char *av[], char *envp[])
{
	struct s_shell	shell;
	int				st;

	(void)av;
	if (ac > 1)
		return (err_msg(2, "usage", "minishell takes no arguments"));
	if (sh_init(&shell, envp) != 0)
	 	return (err_msg(2, "init", "init failed"));
	st = sh_repl(&shell);
	sh_cleanup(&shell);
	return (st & 255);
}
