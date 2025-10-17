/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: garivoir <garivoir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:01:47 by echatela          #+#    #+#             */
/*   Updated: 2025/10/17 16:06:07 by garivoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

//TODO: malloc buf (on peut compter la longueur de pwd
//grace a la variable PWD)
int	sh_pwd(struct s_shell *sh, char **argv)
{
	char	buf[4096];
	
	(void)sh;
	(void)argv;
	printf("%s\n", getcwd(buf, 4096));
	return (0);
}
