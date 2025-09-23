/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:03:16 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:18:36 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = (unsigned char *) str;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			return ((void *)(s + i));
		}
		i++;
	}
	return (NULL);
}
