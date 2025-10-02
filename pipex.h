/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:56:12 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/02 16:44:59 by bedantas         ###   ########.fr       */
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

// pipex_utils.c
void	perror_exit(char *str);
int		input_invalid(int argc, char **argv);

// commands.c
int		open_file(char *argv, int flag);
void	cmd1(char **argv, int *pipe_fd, char **env);
void	cmd2(char **argv, int *pipe_fd, char **env);
void	pid_cmd1(char **argv, char **env, int *pipe_fd, pid_t pid);
void	pid_cmd2(char **argv, char **env, int *pipe_fd, pid_t pid);

// exec.c
void	exec_access_perror(char *s, char **array, int x);
void	exec_access_putstr(char *s, char **array, int x);
void	cmd_bar(char **cmd_split, char **env);
void	cmd_not_bar(char **cmd_split, char **env);
void	exec_cmd(char *argv, char **env);

// exec_utils.c
void	free_array(char **array);
int		bar(char *argv);
char	**path(char **env);
char	*command_valid(char **cmd_split, char **path_split);

#endif
