/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:43:32 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 15:50:58 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	exp_status(int st, struct s_str_b *sb)
{
	char	*str_st;

	str_st = ft_itoa(st);
	if (!str_st)
		return (1);
	if (sb_puts(sb, str_st) != 0)
		return (free(str_st), 1);
	free(str_st);
	return (0);
}

static int	exp_set_var_str(struct s_shell *sh,
	struct s_str_b *sb, const char *str, int *i)
{
	int				n;
	struct s_env	*cur;

	(*i)++;
	if (str[*i] == '?')
		return ((*i)++, exp_status(sh->last_status, sb));
	if (check_quote(str[*i], NULL, NULL))
		return (0);
	if (!ft_isalpha(str[*i]) && str[*i] != '_')
		return (sb_putc(sb, '$'));
	n = 0;
	while (str[*i + n] && (ft_isalnum(str[*i + n]) || str[*i + n] == '_'))
		n++;
	cur = sh->env;
	while (cur)
	{
		if (ft_strncmp(&str[*i], cur->key, n) == 0)
			return (*i += n, sb_puts(sb, cur->val));
		cur = cur->next;
	}
	return (*i += n, 0);
}

static char	*expanded_var_str(struct s_shell *sh, char *str, int mode)
{
	struct s_str_b	sb;
	int				sq;
	int				dq;
	int				i;

	sb_init(&sb);
	sq = 0;
	dq = 0;
	i = -1;
	while (str[++i])
	{
		check_quote(str[i], &sq, &dq);
		if (str[i] == '$' && (!sq || mode == 2)
			&& exp_set_var_str(sh, &sb, str, &i) != 0)
			return (free(sb.out), NULL);
		else if (sb_putc(&sb, str[i]) != 0)
			return (free(sb.out), NULL);
		if (!str[i])
			break ;
	}
	if (add_buf(&sb) != 0)
		return (free(sb.out), NULL);
	return (sb.out);
}

static int	is_redir_ambiguous(char *ref)
{
	int	sq;
	int	dq;
	int	i;

	sq = 0;
	dq = 0;
	i = 0;
	while (is_blank(ref[i]))
		i++;
	if (!ref[i])
		return (1);
	while (ref[i] && !(is_blank(ref[i]) && !sq && !dq))
		check_quote(ref[i++], &sq, &dq);
	while (is_blank(ref[i]) && !sq && !dq)
		i++;
	if (ref[i])
		return (1);
	return (0);
}

int	expand_var(struct s_shell *sh, char **p_arg, int mode)
{
	char	*exp_str;

	exp_str = expanded_var_str(sh, *p_arg, mode);
	if (!exp_str)
		return (err_per(1, "expand"));
	if (mode == 1)
		if (is_redir_ambiguous(exp_str))
			return (free(exp_str), 1);
	free(*p_arg);
	*p_arg = exp_str;
	return (0);
}
