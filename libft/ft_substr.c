/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:38:40 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/21 17:57:17 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*buff;
	size_t			i;
	size_t			buff_size;

	if (!s)
		return (malloc(0));
	buff_size = 0;
	i = 0;
	while (s[i] && i <= start)
		i++;
	if (i >= start)
		while (s[start + buff_size] && buff_size < len)
			buff_size++;
	i = 0;
	buff = malloc((buff_size + 1) * sizeof(unsigned char));
	if (!buff)
		return (0);
	while (i < buff_size)
	{
		buff[i] = s[start + i];
		i++;
	}
	buff[i] = 0;
	return ((char *)buff);
}
