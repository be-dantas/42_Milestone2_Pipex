/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:47 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/30 11:09:45 by bedantas         ###   ########.fr       */
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
		perror_exit("Error open infile");
	return (fd);
}

void	cmd1(char **argv, int *pipe_fd, char **env)
{
	int	new_fd;

	new_fd = open_file(argv[1], 0); //retorna um int do fd novo para depois substituir o fd padrão (0 ou 1) por esse.
	dup2(new_fd, 0); //funcao dup2(valor_novo, valor_antigo) = o fd leitura agora 'e o fd gerado acima
	close(new_fd);
	
	dup2(pipe_fd[1], 1); //o fd de escrita (sa'ida padrao terminal por ex) agora 'e escrito no pipe
	close(pipe_fd[1]);
	close(pipe_fd[0]); //fechar mesmo sem ter usado se nao o programa fica esperando ele ser usado ou da vazamento

	exec_cmd(argv[2], env);
}

void	cmd2(char **argv, int *pipe_fd, char **env)
{
	int	new_fd;

	dup2(pipe_fd[0], 0); //a leitura 'e o que esta em pipe (atualizado pelo preocesso filho)
	close(pipe_fd[0]);
	close(pipe_fd[1]);

	new_fd = open_file(argv[4], 1); //retorna um int do fd novo para depois substituir o fd padrão (0 ou 1) por esse.
	dup2(new_fd, 1); //escreve no arquivo outfile
	close(new_fd);
	
	exec_cmd(argv[3], env);
}
