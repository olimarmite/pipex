/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 22:51:41 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/21 16:09:01 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;

	d = dest;
	if ((dest == NULL && src == NULL))
		return (NULL);
	if (src > dest)
	{
		i = 0;
		while (i < n)
		{
			d[i] = ((const char *)src)[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			d[i - 1] = ((const char *)src)[i - 1];
			i--;
		}
	}
	return (dest);
}
