/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:11:16 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/21 12:40:31 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	i = 0;
	if ((size == 0) || (nmemb == 0))
		return (malloc(0));
	if (((nmemb * size) / size != nmemb))
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	while (i < (nmemb * size))
	{
		mem[i] = 0;
		i++;
	}
	return ((void *)(mem));
}
