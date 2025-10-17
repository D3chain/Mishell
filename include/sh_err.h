/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_err.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:31:59 by echatela          #+#    #+#             */
/*   Updated: 2025/10/11 14:40:45 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ERR_H
# define SH_ERR_H

# define MS_BUF_ERR_SIZE 4096

int	err_msg(int code, const char *ctx, const char *msg);
int	err_per(int code, const char *ctx);
int	err_syn(const char *tok);
int	err_cmd(int code, const char *cmd);
int	err_bui(int code, const char *bi, const char *detail);

int	fill1(char *buf, const char *s);
int	fill2(char *buf, const char *a, const char *b);
int	fill3(char *buf, const char *a, const char *b, const char *c);

#endif