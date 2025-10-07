/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:01 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/07 10:50:18 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	px;

	if (input_invalid(argc, argv))
		return (1);
	if (pipe(px.pipe_fd) == -1)
		perror_exit("");
	px.pid1 = fork();
	if (px.pid1 == -1)
		perror_exit("");
	pid_cmd1(argv, env, px.pipe_fd, px.pid1);
	px.pid2 = fork();
	if (px.pid2 == -1)
		perror_exit("");
	pid_cmd2(argv, env, px.pipe_fd, px.pid2);
	close(px.pipe_fd[0]);
	close(px.pipe_fd[1]);
	waitpid(px.pid1, &px.status1, 0);
	waitpid(px.pid2, &px.status2, 0);
	if (WIFEXITED(px.status2))
		return (WEXITSTATUS(px.status2));
	return (1);
}
