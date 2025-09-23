/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 11:55:52 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:17:54 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t len)
{
	char	*temp;
	size_t	i;

	temp = (char *)s;
	i = 0;
	while (i < len)
	{
		temp[i] = 0;
		i++;
	}
	return (s);
}
