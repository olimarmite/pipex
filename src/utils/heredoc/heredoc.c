/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:56:09 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/10 17:57:09 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <get_next_line.h>

int	read_write(char *limiter, int in_fd, int out_fd)
{
	char	*line;
	int		line_len;
	int		limiter_len;

	ft_putstr_fd("heredoc>", 0);
	line = get_next_line(in_fd);
	limiter_len = ft_strlen(limiter);
	while (line != 0 && (ft_strncmp(limiter, line, limiter_len) != 0
			|| line[limiter_len] != '\n'))
	{
		ft_putstr_fd("heredoc>", 0);
		line_len = ft_strlen(line);
		if (write(out_fd, line, line_len) != line_len)
		{
			free(line);
			get_next_line_close(in_fd);
			return (-1);
		}
		free(line);
		line = get_next_line(in_fd);
	}
	free(line);
	get_next_line_close(in_fd);
	return (0);
}

int	heredoc(char *limiter, char **filename)
{
	int	result;

	result = heredoc_file(limiter, filename);
	if (result == -1)
	{
		ft_putstr_fd("Fallback on memory based heredoc\n", 2);
		result = heredoc_pipe(limiter);
	}
	return (result);
}
