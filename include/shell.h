/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 08:11:37 by echatela          #+#    #+#             */
/*   Updated: 2025/10/23 16:28:28 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "sh_env.h"
# include "sh_lex.h"
# include "sh_par.h"
# include "vec.h"
# include "sh_err.h"
# include "util.h"
# include "libft.h"

# include <sys/types.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

extern volatile sig_atomic_t	g_sigstate;

struct s_shell
{
	struct s_env	*env;
	struct s_node	*root;
	int				last_status;
};

int		sh_repl(struct s_shell *sh);

void	sh_install_signal_mode(int mode);
void	sh_ignore_signal(void);
void	sh_cleanup(struct s_shell *sh);

#endif
