/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:34 by echatela          #+#    #+#             */
/*   Updated: 2025/10/21 13:16:26 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_env.h"

static int	sh_echo_option(char *option)
{
	int	i;

	if (!option)
		return (1);
	if (option[0] != '-')
		return (1);
	i = 1;
	if (!option[i])
		return (1);
	while (option[i])
	{
		if (option[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

int	sh_echo(struct s_shell *sh, char **argv)
{
	int	i;
	int	option;

	(void)sh;
	i = 1;
	option = 1;
	if (argv[i] && sh_echo_option(argv[1]) == 0)
		option = 0;
	while (argv[i] && sh_echo_option(argv[i]) == 0)
		i++;
	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
		if (argv[i])
			printf(" ");
	}
	if (option == 1)
		printf("\n");
	return (0);
}
