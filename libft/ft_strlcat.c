/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 15:28:18 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:21:12 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i_dest;
	size_t	i_src;

	if (!dest && len == 0)
		return (ft_strlen(src));
	i_dest = ft_strlen(dest);
	i_src = 0;
	if (len <= i_dest)
	{
		return (len + ft_strlen(src));
	}
	while ((i_dest + i_src + 1) < len && src[i_src] != '\0')
	{
		dest[i_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[i_dest + i_src] = '\0';
	return (i_dest + ft_strlen(src));
}
