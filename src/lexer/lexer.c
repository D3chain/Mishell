/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:42:06 by echatela          #+#    #+#             */
/*   Updated: 2025/10/13 19:14:01 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "vec.h"

static int	set_next_tok(char **cur, struct s_tok *tok)
{
	while (is_blank(**cur))
		(*cur)++;
	if (**cur == '\0')
		return (tok_eof(tok));
	if (is_meta(**cur))
		return (tok_op(tok, cur));
	else
		return (tok_word(tok, cur));
}

int	lex_line(const char *line, struct s_tok **p_toks)
{
	struct s_vec	tokv;
	struct s_tok	tok;
	char			*cur;

	vec_init(&tokv, sizeof(tok));
	cur = (char *)line;
	tok.type = -1;
	while (tok.type != T_EOF)
	{
		ft_bzero(&tok, sizeof(tok));
		if (set_next_tok(&cur, &tok) != 0)
			return (vec_free(&tokv, tok_free), 1);
		if (vec_push(&tokv, &tok) != 0)
			return (vec_free(&tokv, tok_free), 1);
	}
	*p_toks = tokv.data;
	return (0);
}
