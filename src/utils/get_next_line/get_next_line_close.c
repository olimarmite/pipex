/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_close.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:52:46 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/03 19:55:42 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	get_next_line_close(int fd)
{
	t_vector	**fd_vector;

	fd_vector = get_fd_vector(fd);
	free_vector(fd_vector);
}
