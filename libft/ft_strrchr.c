/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:23:41 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/15 19:07:10 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*src;
	unsigned char	*result;
	unsigned char	cc;

	src = (unsigned char *)s;
	cc = (unsigned char)c;
	result = 0;
	while (*src != 0)
	{
		if (*src == cc)
			result = src;
		src++;
	}
	if (*src == cc)
		result = src;
	return ((char *)(result));
}
