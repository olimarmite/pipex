/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:59:57 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/14 22:46:11 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	cs;

	i = 0;
	sr = (unsigned char *)s;
	cs = (unsigned char)c;
	if (n <= 0)
		return (0);
	while (sr[i] != cs)
	{
		if (i + 1 >= n)
			return (0);
		i++;
	}
	return ((void *)(s + i));
}
