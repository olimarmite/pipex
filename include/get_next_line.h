/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:06:48 by olimarti          #+#    #+#             */
/*   Updated: 2023/03/03 19:58:53 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef FOPEN_MAX
#  define FOPEN_MAX 1024
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# if BUFFER_SIZE < 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

typedef struct s_vector
{
	size_t	capacity;
	size_t	size;
	void	*buff;
}			t_vector;

void		vector_resize_if_needed(t_vector *vector, size_t buff_size);
void		vector_resize(t_vector *vector, size_t new_size, size_t elem_size);
void		vector_insert_buff(t_vector *vector, char *buff, size_t buff_size);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		free_vector(t_vector **vector);
char		*extract_str(char *buff, size_t size, int add_terminator);
t_vector	**get_fd_vector(int fd);
char		*get_next_line(int fd);
void		get_next_line_close(int fd);

#endif
