/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:47:39 by echatela          #+#    #+#             */
/*   Updated: 2025/10/11 13:48:17 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEX_H
# define SH_LEX_H

# include "shell.h"
# include "vec.h"
# include "util.h"

enum e_toktype
{
	T_WORD,
	T_PIPE,
	T_AND,
	T_OR,
	T_LPAR,
	T_RPAR,
	T_RED_IN,
	T_H_DOC,
	T_RED_OUT,
	T_RED_APP,
	T_EOF
};

struct s_tok
{
	enum e_toktype	type;
	char			*lex;
};

int		lex_line(const char *line, struct s_tok **p_toks);
int		tok_word(struct s_tok *tok, char **p);
int		tok_op(struct s_tok *tok, char **p);
int		tok_eof(struct s_tok *tok);
void	toks_free(struct s_tok *toks);
void	tok_free(void *p);

#endif