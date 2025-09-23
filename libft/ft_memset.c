/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:19:50 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:24:37 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < len)
	{
		temp[i] = (unsigned char) value;
		i++;
	}
	return (ptr);
}
