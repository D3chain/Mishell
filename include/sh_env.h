/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 14:44:07 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 15:26:16 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_ENV_H
# define SH_ENV_H

# include "shell.h"

struct s_shell;

enum { ENV_IN, ENV_OUT
};

struct s_env
{
	char			*var;
	char			*key;
	char			*val;
	int				in_out;

	struct s_env	*next;
};

void	env_free(struct s_env **env);
void	env_clear_list(struct s_env **env);
char	**env_create_tab(struct s_env *env);
char	*env_getval(struct s_env *env, char *key);
int		env_new(char *var, struct s_env **result);
int		env_create_list(struct s_shell *sh, char **env_old);

#endif