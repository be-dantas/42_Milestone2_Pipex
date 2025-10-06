/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 17:19:44 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/06 09:09:47 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	bar(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	**path(char **env)
{
	char	*search_path;
	char	**path_split;

	search_path = ft_strstr(env, "PATH");
	if (!search_path)
		return (NULL);
	path_split = ft_split(search_path, ':');
	if (!path_split)
		return (NULL);
	return (path_split);
}

char	*command_valid(char **cmd_split, char **path_split)
{
	int		i;
	char	*temp_path;
	char	*exec;

	i = 0;
	while (path_split[i])
	{
		temp_path = ft_strjoin(path_split[i], "/");
		exec = ft_strjoin(temp_path, cmd_split[0]);
		free(temp_path);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		else if (access(exec, F_OK) == 0 && access(exec, X_OK) != 0)
		{
			free(exec);
			return ((char *)-1);
		}
		free(exec);
		i++;
	}
	return (NULL);
}
