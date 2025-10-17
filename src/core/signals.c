/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:33:29 by echatela          #+#    #+#             */
/*   Updated: 2025/10/13 19:05:32 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

volatile sig_atomic_t	g_sigstate = 0;

static void	sh_sigint_handler(int sig, siginfo_t *info, void *ctx)
{
	(void)info;
	(void)ctx;
	if (sig == SIGINT)
	{
		g_sigstate = SIGINT;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	hd_sigint_handler(int sig, siginfo_t *info, void *ctx)
{
	(void)info;
	(void)ctx;
	if (sig == SIGINT)
	{
		g_sigstate = SIGINT;
		write(1, "\n", 1);
		close(STDIN_FILENO);
	}
}

void	sh_install_signal_mode(int mode)
{
	struct sigaction	sa;

	g_sigstate = 0;
	if (mode == 0)
		sa.sa_sigaction = sh_sigint_handler;
	if (mode == 1)
		sa.sa_sigaction = hd_sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGQUIT, &sa, NULL);
}

void	sh_ignore_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
}
