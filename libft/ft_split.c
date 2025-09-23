/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:06:10 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:20:17 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_array(const char *s, char c)
{
	size_t	len_array;
	size_t	i;

	len_array = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			len_array++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len_array);
}

static size_t	count_string(const char *s, size_t i_end, char c)
{
	while (s[i_end] != '\0' && s[i_end] != c)
		i_end++;
	return (i_end);
}

static void	free_array(char **array, size_t i)
{
	while (i > 0)
		free(array[--i]);
	free(array);
}

static int	malloc_array(char **array, const char *s, char c, size_t len_array)
{
	size_t	i_array;
	size_t	i_start;
	size_t	i_end;
	size_t	k;

	i_array = 0;
	i_start = 0;
	while (i_array < len_array)
	{
		while (s[i_start] == c)
			i_start++;
		i_end = count_string(s, i_start, c);
		array[i_array] = (char *)malloc((i_end - i_start + 1) * sizeof(char));
		if (!array[i_array])
		{
			free_array(array, i_array);
			return (0);
		}
		k = 0;
		while (i_start < i_end)
			array[i_array][k++] = s[i_start++];
		array[i_array][k] = '\0';
		i_array++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	len_array;
	char	**array;

	if (!s)
		return (NULL);
	len_array = count_array(s, c);
	array = (char **)malloc((len_array + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	if (!malloc_array(array, s, c, len_array))
		return (NULL);
	array[len_array] = NULL;
	return (array);
}
