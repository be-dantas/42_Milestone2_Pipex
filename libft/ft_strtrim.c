/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:43:41 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:21:58 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	s2 = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!s2)
		return (NULL);
	while (start < end)
		s2[i++] = s1[start++];
	s2[i] = '\0';
	return (s2);
}
