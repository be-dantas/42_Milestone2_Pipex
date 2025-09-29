/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:01 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/29 15:19:50 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perror_exit(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

int	input_invalid(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5)
		return (0);
	while (argv)
	{
		if (argv[i][0] == "\0")
			return (0);
		i++;
	}
	return (1);
}

int main (int argc, char **argv, char **env)
{
	int		pipe_fd[2]; //na função pipe ele enche esse array de int com a saída pipe 0 e 1 (leitura e escrita)
	int		pipe_result;
	pid_t	pid;

	if (!input_invalid(argc, argv))
		perror_exit("./pipex infile cmd1 cmd2 outfile\n");

	pipe_result = pipe(pipe_fd);
	if (pipe_result == -1)
		perror_exit("Error pipe");

	pid = fork();
	if (pid == -1)
		perror_exit("Error pid");
	if (pid == 0) //se for o primeiro processo (cmd1/filho)
		{
			cmd1(argv, pipe_fd, env);
			exit(EXIT_SUCCESS);
		}
	// função waitpid
	// função do cmd2 (pai);
	return (0);
}

