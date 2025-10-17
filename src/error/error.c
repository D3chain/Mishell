/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:33:50 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 15:18:41 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_err.h"

int	err_msg(int code, const char *ctx, const char *msg)
{
	char	err_buf[MS_BUF_ERR_SIZE];
	int		i;

	if (ft_strlen(ctx) + ft_strlen(msg) + 16 > MS_BUF_ERR_SIZE -1)
		write(2, "miniprout: pipi popo\n", 22);
	i = 0;
	ft_bzero(err_buf, MS_BUF_ERR_SIZE);
	i += fill2(err_buf, "minishell: ", ctx);
	i += fill2(err_buf + i, ": ", msg);
	i += fill1(err_buf + i, "\n");
	write(2, err_buf, i);
	return (code);
}

int	err_per(int code, const char *ctx)
{
	char	err_buf[MS_BUF_ERR_SIZE];
	int		i;

	if (ft_strlen(ctx) + ft_strlen(strerror(errno)) + 14 > MS_BUF_ERR_SIZE -1)
		write(2, "miniprout: pipi popo\n", 22);
	i = 0;
	i += fill2(err_buf, "minishell: ", ctx);
	i += fill3(err_buf + i, ": ", strerror(errno), "\n");
	write(2, err_buf, i);
	return (code);
}

int	err_syn(const char *tok)
{
	char	err_buf[MS_BUF_ERR_SIZE];
	int		i;

	if (ft_strlen(tok) + 48 > MS_BUF_ERR_SIZE - 1)
		write(2, "miniprout: pipi popo\n", 22);
	i = 0;
	i += fill3(err_buf,
			"minishell: syntax error near unexpected token `", tok, "\'\n");
	write(2, err_buf, i);
	return (2);
}

int	err_cmd(int code, const char *cmd)
{
	if (code == 1261)
	{
		err_msg(code, cmd, "is a directory");
		return (126);
	}
	if (code == 127)
		err_msg(code, cmd, "command not found");
	else if (code == 126)
		err_msg(code, cmd, "permission denied");
	else
		err_per(2, cmd);
	return (code);
}

int	err_bui(int code, const char *bi, const char *detail)
{
	char	err_buf[MS_BUF_ERR_SIZE];
	int		i;

	if (ft_strlen(bi) + ft_strlen(detail) + 14 > MS_BUF_ERR_SIZE -1)
		write(2, "miniprout: pipi popo\n", 22);
	i = 0;
	i += fill3(err_buf, "minishell: ", bi, ": ");
	i += fill2(err_buf + i, detail, "\n");
	return (code);
}
