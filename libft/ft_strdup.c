/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:56:44 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/15 18:34:33 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*buff;

	len = ft_strlen(s);
	i = 0;
	buff = malloc((len + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	while (i <= (len))
	{
		buff[i] = s[i];
		i++;
	}
	return (buff);
}
