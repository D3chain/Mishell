/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 09:25:21 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 11:54:56 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static char	*sh_read_line(void)
{
	char	*line;

	line = readline("minishell$ ");
	if (line && *line)
		add_history(line);
	return (line);
}

static int	sh_process_line(struct s_shell *sh, char *line)
{
	struct s_tok	*toks;
	struct s_node	*ast;
	int				st;

	st = 0;
	if (!line || !*line)
		return (0);
	if (lex_line(line, &toks) != 0)
		return (free(line), 2);
	free(line);
	if (par_build(toks, &ast) != 0)
		return (toks_free(toks), 2);
	toks_free(toks);
	if (rd_hdoc_process_all(sh, ast) != 0)
		return (sh_cleanup(sh), sh->last_status);
	sh->root = ast;
	st = sh_run_node(sh, ast);
	free_node(sh->root);
	sh->root = NULL;
	return (st);
}

int	sh_repl(struct s_shell *sh)
{
	char	*line;
	int		st;

	while (1)
	{
		sh_install_signal_mode(0);
		line = sh_read_line();
		if (!line)
			return (write(2, "exit\n", 5), 130);
		st = sh_process_line(sh, line);
		sh->last_status = st;
	}
	return (st);
}
