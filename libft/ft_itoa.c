/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 23:29:22 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/23 12:25:03 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	calc_positive_number_size(int nb)
{
	int	number_size;

	number_size = 1;
	while (nb >= 10)
	{
		number_size++;
		nb = nb / 10;
	}
	return (number_size);
}

static char	*itoa_dest(char *buff, int n, int number_size, int is_negative)
{
	buff[number_size + is_negative] = 0;
	number_size--;
	if (is_negative)
		buff[0] = '-';
	while (number_size >= 0)
	{
		buff[number_size + is_negative] = (n % 10) + 48;
		n = n / 10;
		number_size--;
	}
	return (buff);
}

char	*ft_itoa(int n)
{
	int		number_size;
	int		is_negative;
	char	*buff;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		is_negative = 1;
	}
	number_size = calc_positive_number_size(n);
	buff = malloc(sizeof(char) * (number_size + is_negative + 1));
	if (!buff)
		return (NULL);
	return (itoa_dest(buff, n, number_size, is_negative));
}
