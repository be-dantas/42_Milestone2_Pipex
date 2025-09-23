/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 11:17:05 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:20:04 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;
	char	c;

	ln = (long)n;
	if (!fd || fd < 0)
		fd = 1;
	if (ln < 0)
	{
		write (fd, "-", 1);
		ln = -ln;
	}
	if (ln >= 10)
		ft_putnbr_fd(ln / 10, fd);
	c = (ln % 10) + '0';
	write (fd, &c, 1);
}
