/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:56:12 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/30 12:12:32 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h> //para pid_t
# include <fcntl.h> //para O_RDONLY...
# include <sys/wait.h> // para waitpid
# include <stdio.h>  // Para perror()
# include <errno.h>  // Para errno
# include "./libft/libft.h"

// pipex.c
void	perror_exit(char *str);
int		input_invalid(int argc, char **argv);

// commands.c
int		open_file(char *argv, int flag);
void	cmd1(char **argv, int *pipe_fd, char **env);
void	cmd2(char **argv, int *pipe_fd, char **env);

// exec.c
void	free_array(char **array);
char	**path(char **env);
char	*command_valid(char **cmd_split, char **path_split);
void	exec_cmd(char *argv, char **env);

#endif
