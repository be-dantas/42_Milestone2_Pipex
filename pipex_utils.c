/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:01 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/06 16:01:33 by bedantas         ###   ########.fr       */
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
	if (argc != 5)
		return (1);
	if (argv[1][0] == '\0' && argv[2][0] == '\0'
		&& argv[3][0] == '\0' && argv[4][0] == '\0')
		return (1);
	if (argv[2][0] == '\0')
	{
		ft_putstr_fd("Permission denied\n", 1);
		exit(0);
	}
	else if (argv[3][0] == '\0')
	{
		ft_putstr_fd("Permission denied\n", 1);
		exit(126);
	}
	return (0);
}
