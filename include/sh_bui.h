/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:43:38 by echatela          #+#    #+#             */
/*   Updated: 2025/10/23 22:22:08 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUI_H
# define SH_BUI_H

enum { EXP_ADD, EXP_APPEND, EXP_UPDATE, EXP_NO, EXP_MALLOC_ERR
};

int				is_builtin(char *cmd);
int				run_builtin(struct s_shell *sh, struct s_cmd *cmd);
int				exec_builtin(struct s_shell *sh, int std_fds[2], char **argv);

char			*sh_export_key(char *argv);
int				sh_export_new_var(struct s_env *env);
int				sh_export_no_arg(struct s_shell *sh);
int				sh_cd(struct s_shell *sh, char **argv);
int				sh_env(struct s_shell *sh, char **argv);
int				sh_pwd(struct s_shell *sh, char **argv);
int				sh_echo(struct s_shell *sh, char **argv);
int				sh_exit(struct s_shell *sh, char **argv);
int				sh_unset(struct s_shell *sh, char **argv);
int				sh_export(struct s_shell *sh, char **argv);
struct s_env	*sh_export_env_key(struct s_shell *sh, char *key);
int				sh_export_scan_arg(struct s_shell *sh, char *argv);

#endif