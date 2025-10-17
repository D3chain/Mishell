/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echatela <echatela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 15:12:12 by echatela          #+#    #+#             */
/*   Updated: 2025/10/16 15:18:28 by echatela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "sh_exe.h"

static char	*join_path_command(char *path, char *cmd)
{
	char	*path_cmd;
	char	*tmp;

	if (!path[0])
		return (ft_strjoin("./", cmd));
	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	path_cmd = ft_strjoin(tmp, cmd);
	free(tmp);
	return (path_cmd); 
}

static char	*get_path_command(char *cmd, char **p_val)
{
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while ((*p_val)[i] && (*p_val)[i] != ':')
		i++;
	path = ft_substr(*p_val, 0, i);
	if (!path)
		return (err_per(1, "exec"), NULL);
	*p_val += i;
	if (**p_val == ':')
		(*p_val)++;
	tmp = join_path_command(path, cmd);
	free(path);
	path = tmp;
	return (path);
}

static int	check_path(char *path, int mode)
{
	struct stat	sb;

	if (access(path, F_OK) == 0)
	{
		if (stat(path, &sb) != 0)
			return (2);
		if (S_ISDIR(sb.st_mode))
			return (free(path), 1261);
		if (access(path, X_OK) != 0)
			return (free(path), 127);
		return (0);
	}
	if (mode == 1)
		return (free(path), -1);
	return (free(path), 126);
}

int	find_valid_path(char **p_path_cmd, char *path_val, char *cmd)
{
	int		st;

	if (ft_strchr(cmd, '/') || path_val == NULL)
	{
		*p_path_cmd = ft_strdup(cmd);
		if (!*p_path_cmd)
			return (2);
		st = check_path(*p_path_cmd, 0);
		return (st);
	}
	while (*path_val)
	{
		*p_path_cmd = get_path_command(cmd, &path_val);
		if (!*p_path_cmd)
			return (2);
		st = check_path(*p_path_cmd, 1);
		if (st != -1)
			return (st);
	}
	return (127);
}