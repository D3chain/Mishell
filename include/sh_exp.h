/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:31:51 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 10:08:14 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXP_H
# define SH_EXP_H

# include <dirent.h>

int		expand_command(struct s_shell *sh, struct s_cmd *cmd);

int		expand_var(struct s_shell *sh, char **p_arg, int mode);
int		split_arg(struct s_vec *arg_vec, char *arg);
void	unblank_str(char *str, int sq, int dq);

int		expand_wc(char **ref, struct s_vec *argv);

int		exp_unquote_str(char *str, int sq, int dq);

#endif
