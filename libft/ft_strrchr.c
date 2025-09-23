/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:27:59 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:21:50 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	size_t	str_len;

	s = (char *) str;
	str_len = ft_strlen(s);
	while (str_len > 0)
	{
		if (s[str_len] == (char)c)
			return (&s[str_len]);
		str_len--;
	}
	if (s[0] == (char)c)
		return (&s[0]);
	return (NULL);
}
