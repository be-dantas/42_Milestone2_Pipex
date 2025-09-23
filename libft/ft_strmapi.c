/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 16:34:22 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:21:31 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len_s;
	char			*s2;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len_s = ft_strlen(s);
	s2 = (char *)malloc(sizeof(char) * len_s + 1);
	if (!s2)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
