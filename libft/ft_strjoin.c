/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:02:01 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/21 22:11:55 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			s1_len;
	size_t			s2_len;
	unsigned char	*buff;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buff = malloc((s1_len + s2_len + 1) * sizeof(unsigned char));
	if (!buff)
		return (NULL);
	ft_memcpy(buff, s1, s1_len);
	ft_memcpy(buff + s1_len, s2, s2_len + 1);
	return ((char *)buff);
}
