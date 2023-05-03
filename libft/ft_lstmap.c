/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:13:49 by olimarti          #+#    #+#             */
/*   Updated: 2022/11/21 22:55:45 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*node_dup;

	dest = NULL;
	if (f == NULL)
		return (NULL);
	while (lst != NULL)
	{
		node_dup = ft_lstnew(lst->content);
		if (!node_dup)
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, node_dup);
		node_dup->content = f(lst->content);
		lst = lst->next;
	}
	return (dest);
}
