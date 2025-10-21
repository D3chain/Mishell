/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:15 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 13:19:33 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static int	sh_exit_numeric_code(char *argv)
{
	int	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (1);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	sh_exit(struct s_shell *sh, char **argv)
{
	long	exit_code;

	printf("exit\n");
	if (!argv[1])
		(sh_cleanup(sh), exit(0));
	if (argv[1] && argv[2])
		return (sh_cleanup(sh),
			write(2, "bash: exit: too many arguments\n", 31), 1);
	if (sh_exit_numeric_code(argv[1]) != 0)
	{
		write(2, "bash: exit: ", 12);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": numeric argument required\n", 29);
		exit(2);
	}
	exit_code = ft_atol(argv[1]);
	exit((unsigned char)exit_code);
	return (0);
}
