/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:11:41 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/21 17:55:20 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_size;

	if ((!big || !little) && len == 0)
		return (NULL);
	i = 0;
	little_size = ft_strlen(little);
	if (*little == 0)
		return ((char *)big);
	while ((big[i] != 0) && (i + little_size) <= len)
	{
		j = 0;
		while ((little[j] != 0) && (big[i + j] == little[j]))
			j++;
		if (little[j] == 0)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
