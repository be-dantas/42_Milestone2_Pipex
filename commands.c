/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:47 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/06 09:08:15 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *argv, int flag)
{
	int	fd;

	fd = 0;
	if (flag == 0)
		fd = open(argv, O_RDONLY, 0444);
	if (flag == 1)
		fd = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror(argv);
		exit(1);
	}
	return (fd);
}

void	cmd1(char **argv, int *pipe_fd, char **env)
{
	int	new_fd;

	new_fd = open_file(argv[1], 0);
	dup2(new_fd, 0);
	close(new_fd);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	exec_cmd(argv[2], env);
}

void	cmd2(char **argv, int *pipe_fd, char **env)
{
	int	new_fd;

	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	new_fd = open_file(argv[4], 1);
	dup2(new_fd, 1);
	close(new_fd);
	exec_cmd(argv[3], env);
}

void	pid_cmd1(char **argv, char **env, int *pipe_fd, pid_t pid)
{
	if (pid == -1)
		perror_exit("");
	if (pid == 0)
	{
		cmd1(argv, pipe_fd, env);
		exit(EXIT_FAILURE);
	}
}

void	pid_cmd2(char **argv, char **env, int *pipe_fd, pid_t pid)
{
	if (pid == -1)
		perror_exit("");
	if (pid == 0)
	{
		cmd2(argv, pipe_fd, env);
		exit(EXIT_FAILURE);
	}
}
