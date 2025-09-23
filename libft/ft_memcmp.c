/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:44:06 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:19:37 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_one;
	unsigned char	*s_two;
	size_t			i;

	s_one = (unsigned char *) s1;
	s_two = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (s_one[i] != s_two[i])
		{
			return (s_one[i] - s_two[i]);
		}
		i++;
	}
	return (0);
}
