/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:00:04 by echatela          #+#    #+#             */
/*   Updated: 2025/10/23 14:36:41 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_par.h"

static int	par_word(struct s_tok *toks, int *i, struct s_vec *argv)
{
	char	*word;

	if (toks[*i].type != T_WORD)
		return (0);
	if (!are_quotes_closed(toks[*i].lex))
		return (2);
	word = ft_strdup(toks[*i].lex);
	if (!word || vec_push(argv, &word) != 0)
		return (1);
	++(*i);
	return (0);
}

static int	par_redir(struct s_tok *toks, int *i, struct s_vec *redv)
{
	struct s_redir	redir;

	if (!(toks[*i].type >= T_RED_IN && toks[*i].type <= T_RED_APP))
		return (0);
	redir.type = toks[*i].type - 6;
	++(*i);
	if (toks[*i].type != T_WORD)
		return (3);
	if (!are_quotes_closed(toks[*i].lex))
		return (2);
	redir.arg = ft_strdup(toks[*i].lex);
	if (!redir.arg)
		return (1);
	redir.fd[0] = -1;
	redir.fd[1] = -1;
	if (vec_push(redv, &redir) != 0)
		return (free(redir.arg), 1);
	++(*i);
	return (0);
}

static struct s_node	*par_simple(struct s_tok *toks, int *i, int *st)
{
	struct s_node	*new;
	struct s_vec	argv;
	struct s_vec	redv;

	vec_init(&argv, sizeof(char *));
	vec_init(&redv, sizeof(struct s_redir));
	new = ft_calloc(1, sizeof(*new));
	if (!new)
		return (NULL);
	new->kind = N_SIMPLE;
	while (toks[*i].type == T_WORD
		|| (toks[*i].type >= T_RED_IN && toks[*i].type <= T_RED_APP))
	{
		*st = par_word(toks, i, &argv);
		if (*st != 0)
			return (vec_free(&argv, arg_free),
				vec_free(&redv, redir_free), NULL);
		*st = par_redir(toks, i, &redv);
		if (*st != 0)
			return (vec_free(&argv, arg_free),
				vec_free(&redv, redir_free), NULL);
	}
	new->u.s_simple.argv = argv.data;
	new->u.s_simple.redv = redv.data;
	return (new);
}

static struct s_node	*par_subshell(struct s_tok *toks, int *i, int *st)
{
	struct s_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->kind = N_SUBSHELL;
	new->u.s_subshell.list = (++(*i), par_list(toks, i, st));
	if (!new->u.s_subshell.list)
		return (free(new), NULL);
	if (toks[*i].type != T_RPAR)
		return (*st = 3, NULL);
	++(*i);
	return (new);
}

struct s_node	*par_command(struct s_tok *toks, int *i, int *st)
{
	struct s_node	*new;

	if (toks[*i].type == T_LPAR)
		new = par_subshell(toks, i, st);
	else if (toks[*i].type == T_WORD
		|| (toks[*i].type >= T_RED_IN && toks[*i].type <= T_RED_APP))
		new = par_simple(toks, i, st);
	else
		return (*st = 3, NULL);
	if (!new)
		return (NULL);
	return (new);
}
