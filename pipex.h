/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:56:12 by bedantas          #+#    #+#             */
/*   Updated: 2025/09/24 16:52:49 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h> //para pid_t
# include <fcntl.h> //para O_RDONLY...
# include "./libft/libft.h"

// pipex.c
void	perror_exit(char *str);
int	    input_invalid(int argc, char **argv);

// commands.c
int     open_file(char *argv, int flag);
void	cmd1(char **argv, int *pipe_fd, char **env);
void	cmd2(char **argv, int *pipe_fd, char **env);

// exec.c


#endif