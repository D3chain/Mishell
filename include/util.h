/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:33:37 by echatela          #+#    #+#             */
/*   Updated: 2025/10/14 13:26:03 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# define SB_BUF_SIZE 4096

struct s_str_b
{
	char		*out;
	char		buf[SB_BUF_SIZE];
	int			i_buf;
};

void	sb_init(struct s_str_b *sb);
int		sb_putc(struct s_str_b *sb, char c);
int		sb_puts(struct s_str_b *sb, char *s);
int		add_buf(struct s_str_b *sb);


int	is_blank(int c);
int	is_meta(int c);
int	check_quote(char c, int *in_sq, int *in_dq);
int	are_quotes_closed(char *s);

int	wstatus(int st);
int	exit_code_errno(int err);

#endif