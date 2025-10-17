/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:44:07 by echatela          #+#    #+#             */
/*   Updated: 2025/10/15 17:04:17 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# include "shell.h"

struct s_shell;

struct s_env
{
	char			*var;
	char			*key;
	char			*val;
	struct s_env	*next;
};

int		env_create_list(struct s_shell *sh, char **env_old);
void	env_clear_list(struct s_env **env);
char	**env_create_tab(struct s_env *env);
void	env_free(struct s_env **env);
int		env_before_equal_sign(char *var);
int		env_after_equal_sign(char *var);
void	env_var_name_value(struct s_env *env);
int		env_new(char *var, struct s_env **result);

#endif