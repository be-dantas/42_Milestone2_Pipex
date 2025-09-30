/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 16:49:07 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/30 12:12:39 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**path(char **env)
{
	char	*search_path;
	char	**path_split;

	search_path = ft_strstr(env, "PATH");
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
		if (access(exec, F_OK | X_OK) == 0)
		{
			free(temp_path);
			return (exec);
		}
		free(temp_path);
		free(exec);
		i++;
	}
	return (NULL);
}

void	exec_cmd(char *argv, char **env)
{
	char	**cmd_split;
	char	**path_split;
	char	*exec;

	cmd_split = ft_split(argv, ' ');
	if (!cmd_split)
		exit (EXIT_FAILURE);
		
	path_split = path(env);
	if (!path_split)
		exit (EXIT_FAILURE);

	exec = command_valid(cmd_split, path_split);
	if (!exec || execve(exec, cmd_split, env) == -1)
	{
		free_array(cmd_split);
		free_array(path_split);
		perror_exit("Command invalid");
	}
}
