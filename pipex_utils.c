/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:55:01 by bedantas          #+#    #+#             */
/*   Updated: 2025/10/01 18:00:46 by bedantas         ###   ########.fr       */
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
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			return (0);
		i++;
	}
	return (1);
}
