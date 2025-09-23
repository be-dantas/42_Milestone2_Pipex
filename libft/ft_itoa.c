/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:27:51 by bedantas          #+#    #+#             */
/*   Updated: 2025/07/29 11:19:05 by bedantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_n(long temp_pos_n, size_t len_n)
{
	while (temp_pos_n != 0)
	{
		temp_pos_n = temp_pos_n / 10;
		len_n++;
	}
	return (len_n);
}

static void	ft_str(char *str, long pos_n, size_t len_n)
{
	str[len_n] = '\0';
	while (len_n > 0)
	{
		str[len_n -1] = (pos_n % 10) + '0';
		pos_n = pos_n / 10;
		len_n--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len_n;
	long	pos_n;
	long	temp_pos_n;

	len_n = 0;
	pos_n = (long)n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		pos_n = -pos_n;
		len_n = 1;
	}
	temp_pos_n = pos_n;
	len_n = ft_count_n(temp_pos_n, len_n);
	str = (char *)malloc((len_n + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_str(str, pos_n, len_n);
	if (n < 0)
		str[0] = '-';
	return (str);
}
