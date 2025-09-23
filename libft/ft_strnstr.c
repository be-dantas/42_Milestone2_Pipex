/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:19:26 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:21:43 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	n = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (h < len && haystack[h] != '\0')
	{
		while ((haystack[h + n] != '\0')
			&& (haystack[h + n] == needle[n]) && (h + n) < len)
		{
			n++;
			if (needle[n] == '\0')
				return ((char *)haystack + h);
		}
		h++;
		n = 0;
	}
	return (0);
}
