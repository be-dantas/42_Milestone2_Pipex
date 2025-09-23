/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:18:00 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:18:00 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
	{
		array = malloc(1);
		return (array);
	}
	array = (void *)malloc(nmemb * size);
	if (!array)
		return (NULL);
	ft_bzero(array, size * nmemb);
	return (array);
}
