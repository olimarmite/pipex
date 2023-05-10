/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 23:19:12 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/10 15:51:31 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*name_gen(char *directory, char *basename, int nb)
{
	char	*result;
	char	*nb_alpha;
	int		i;

	i = 0;
	nb_alpha = ft_itoa(nb);
	if (nb_alpha == NULL)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(directory) + ft_strlen(basename)
				+ ft_strlen(nb_alpha) + 2));
	i = ft_strcpy(result + i, directory);
	result[i] = '/';
	i++;
	i += ft_strcpy(result + i, basename);
	i += ft_strcpy(result + i, nb_alpha);
	result[i] = '\0';
	free(nb_alpha);
	return (result);
}

char	*heredoc_file_name(char *directory)
{
	int		i;
	char	*path;

	i = 0;
	if (access(directory, W_OK | R_OK) != 0)
		return (NULL);
	path = name_gen(directory, "pipex_hd", i);
	while (access(path, F_OK) == 0)
	{
		free(path);
		path = name_gen(directory, "pipex_hd", i);
		i++;
	}
	printf("-%s-\n", path);
	return (path);
}

int	create_heredoc_file(int fd[2], char **filepath)
{
	char	*path;

	*filepath = NULL;
	path = heredoc_file_name("/tmp");
	if (path == NULL)
		return (1);
	fd[0] = -1;
	fd[1] = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (fd[1] == -1)
	{
		free(path);
		return (1);
	}
	fd[0] = open(path, O_RDONLY, 0600);
	*filepath = path;
	if (fd[1] == -1)
		return (1);
	return (0);
}

int	heredoc_file(char *limiter, char **filename)
{
	int		pipefd[2];

	if (create_heredoc_file(pipefd, filename) != 0)
	{
		perror("file pipe");
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
