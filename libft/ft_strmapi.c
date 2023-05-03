/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:03:47 by olivier           #+#    #+#             */
/*   Updated: 2022/11/21 22:31:37 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned char	*buff;

	if (!s || !f)
		return (NULL);
	i = 0;
	buff = (unsigned char *)ft_strdup(s);
	if (!buff)
		return (NULL);
	while (buff[i])
	{
		buff[i] = f(i, buff[i]);
		i++;
	}
	return ((char *)(buff));
}
