/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:01 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/23 15:03:22 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main (int argc, char **argv, char **env) //env é um arquivo no shell com diversas infos, icomo o PATH
{
	int		pipe_fd[2]; //na função pipe ele enche esse array de int com a saída 0 e 1 (leitura e escrita)
	int		pipe_result;
	pid_t	pid;

	if (argc != 5)
		perror_exit("./pipex infile cmd1 cmd2 outfile\n");
	pipe_result = pipe(pipe_fd[2]);
	if (pipe_result == -1) //-1 se não tiver memória.
		perror_exit("Error pipe");
	pid = fork();
	if (pid == -1) //-1 se não tiver memória.
		perror_exit("Error pid");
	if (pid == 0) //se for o primeiro processo (filho)
		// função do cmd1 (filho);
	// função waitpid
	// função do cmd2 (pai);
	return (0);
}
