/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bui.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:43:38 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 17:01:05 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUI_H
# define SH_BUI_H

int	run_builtin(struct s_shell *sh, struct s_cmd *cmd);
int	is_builtin(char *cmd);
int	exec_builtin(struct s_shell *sh, int std_fds[2], char **argv);

int	sh_cd(struct s_shell *sh, char **argv);
int	sh_echo(struct s_shell *sh, char **argv);
int	sh_env(struct s_shell *sh, char **argv);
int	sh_exit(struct s_shell *sh, char **argv);
int	sh_export(struct s_shell *sh, char **argv);
int	sh_pwd(struct s_shell *sh, char **argv);
int	sh_unset(struct s_shell *sh, char **argv);

#endif