/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:54:26 by echatela          #+#    #+#             */
/*   Updated: 2025/10/14 08:57:56 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lex.h"

int	tok_word(struct s_tok *tok, char **p)
{
	int	len;
	int	sq;
	int	dq;

	len = 0;
	sq = 0;
	dq = 0;
	while ((*p)[len])
	{
		if ((is_blank((*p)[len]) || is_meta((*p)[len])) && !sq && !dq)
			break ;
		check_quote((*p)[len], &sq, &dq);
		len++;
	}
	tok->type = T_WORD;
	tok->lex = ft_substr(*p, 0, len);
	if (!tok->lex)
		return (err_per(1, "lexer"));
	*p += len;
	return (0);
}

int	tok_op(struct s_tok *tok, char **p)
{
	int				i;
	const char		*op[]
		= {0, "|", "&&", "||", "(", ")", "<", "<<", ">", ">>"};

	i = sizeof(op) / sizeof(*op);
	while (op[--i])
	{
		if (ft_strncmp(*p, op[i], ft_strlen(op[i])) == 0)
		{
			tok->type = i;
			tok->lex = ft_strdup(op[i]);
			if (!tok->lex)
				return (err_per(1, "lexer"));
			*p += ft_strlen(op[i]);
			return (0);
		}
	}
	tok->type = -1;
	tok->lex = ft_substr(*p, 0, 1);
	if (!tok->lex)
		return (err_per(1, "lexer"));
	return (err_syn(tok->lex));
}

int	tok_eof(struct s_tok *tok)
{
	tok->type = T_EOF;
	tok->lex = ft_strdup("newline");
	if (!tok->lex)
		return (err_per(1, "lexer"));
	return (0);
}

void	toks_free(struct s_tok *toks)
{
	int	i;

	if (!toks)
		return ;
	i = -1;
	while (toks[++i].type != T_EOF)
		free(toks[i].lex);
	free(toks[i].lex);
	free(toks);
}
