/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_builder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:34:12 by echatela          #+#    #+#             */
/*   Updated: 2025/10/14 09:14:04 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	add_buf(struct s_str_b *sb)
{
	char	*tmp;

	tmp = ft_strjoin(sb->out, sb->buf);
	if (!tmp)
		return (1);
	free(sb->out);
	sb->out = tmp;
	ft_bzero(sb->buf, SB_BUF_SIZE * sizeof(char));
	sb->i_buf = 0;
	return (0);
}

void	sb_init(struct s_str_b *sb)
{
	sb->out = NULL;
	ft_bzero(sb->buf, SB_BUF_SIZE * sizeof(char));
	sb->i_buf = 0;
}

int	sb_puts(struct s_str_b *sb, char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (sb_putc(sb, *s))
			return (1);
		s++;
	}
	return (0);
}

int	sb_putc(struct s_str_b *sb, char c)
{
	if (sb->i_buf == SB_BUF_SIZE - 2)
		if (add_buf(sb) != 0)
			return (1);
	sb->buf[sb->i_buf] = c;
	sb->i_buf++;
	return (0);
}
