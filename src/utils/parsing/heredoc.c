/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 11:56:09 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/09 00:49:27 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
#include <get_next_line.h>

int	read_write(char *limiter, int in_fd, int out_fd)
{
	char	*line;
	int		line_len;

	ft_putstr_fd("heredoc>", 0);
	line = get_next_line(in_fd);
	while (line != 0 && ft_strncmp(limiter, line, ft_strlen(limiter)) != 0)
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

int	heredoc(char *limiter)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	if (read_write(limiter, STDIN_FILENO, pipefd[1]) != 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}
