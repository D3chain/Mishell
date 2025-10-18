/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 11:31:51 by echatela          #+#    #+#             */
/*   Updated: 2025/10/18 18:15:56 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXP_H
# define SH_EXP_H

# include <dirent.h>

int		expand_command(struct s_shell *sh, struct s_cmd *cmd);

int		expand_var(struct s_shell *sh, char **p_arg, int mode);
int		split_arg(struct s_vec *arg_vec, char *arg, int sq, int dq);
void	unblank_str(char *str, int sq, int dq);

int		expand_wc_arg(struct s_vec *arg_vec, char *arg);
int		expand_wc_red(char **p_red);
int		expand_arg_in_vec(struct s_vec *tmp_vec, char *arg);
int		is_expandable(const char *ref, int in_sq, int in_dq);

int		exp_unquote_str(char *str, int sq, int dq);

#endif
