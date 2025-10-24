/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exe.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 19:12:00 by echatela          #+#    #+#             */
/*   Updated: 2025/10/24 11:58:51 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXE_H
# define SH_EXE_H

# include "shell.h"
# include "sh_bui.h"
# include "sys/stat.h"
# include <fcntl.h>
# include <wait.h>

int		rd_hdoc_process_all(struct s_shell *sh, struct s_node *node);
int		sh_run_node(struct s_shell *sh, struct s_node *ast);
int		exe_run_simple(struct s_shell *sh, struct s_cmd *cmd);
int		exe_run_pipeline(struct s_shell *sh, struct s_node **v, int n);
int		exe_run_subshell(struct s_shell *sh, struct s_node *sub);

int		exec_command(struct s_shell *sh, char **argv);
int		find_valid_path(char **p_path_cmd, char *path_val, char *cmd);

int		redir_apply(struct s_redir *redv);

#endif