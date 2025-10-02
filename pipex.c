/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:01 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/02 17:07:06 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		pipe_fd[2];
	int		pipe_result;
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (!input_invalid(argc, argv))
		return (1);
		
	pipe_result = pipe(pipe_fd);
	if (pipe_result == -1)
		perror_exit("");

	pid1 = fork();
	if (pid1 == -1)
		perror_exit("");
	pid_cmd1(argv, env, pipe_fd, pid1);

	pid2 = fork();
	if (pid2 == -1)
		perror_exit("");
	pid_cmd2(argv, env, pipe_fd, pid2);

	close(pipe_fd[0]);
	close(pipe_fd[1]);

	waitpid(pid1, NULL, 0);        // espera o primeiro (não importa status)
	waitpid(pid2, &status, 0);     // espera o último (importa status)
	
	if (WIFEXITED(status))
		return (WEXITSTATUS(status)); // retorna status do cmd2
	return (1);
}
