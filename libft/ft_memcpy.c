/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:16:02 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:19:41 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char			*d;
	const unsigned char		*s;
	size_t					i;

	d = (unsigned char *) dest;
	s = (const unsigned char *) src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < len)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
