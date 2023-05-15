/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:17:33 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/15 13:27:27 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>
#include <sys/wait.h>

void	clean_and_exit(t_execflow params)
{
	destroy_commands(&params.commands, params.command_count);
	free(params.input.filename);
	exit(errno);
}

void	spawn_last_child(t_execflow params, int prev_wr_fd, int out_fd,
	char *envp[])
{
	int	cpid;

	cpid = fork();
	if (cpid == -1)
		perror("fork");
	if (cpid == 0)
	{
		child(prev_wr_fd, out_fd,
			params.commands[params.command_count - 1], envp);
		check_close(prev_wr_fd);
		check_close(out_fd);
		clean_and_exit(params);
	}
	check_close(out_fd);
	check_close(prev_wr_fd);
	close(out_fd);
}

int	spawn_commands(t_execflow params, int prev_wr_fd, int out_fd,
	char *envp[])
{
	int	pipefd[2];
	int	i;
	int	cpid;

	i = -1;
	while (++i < params.command_count - 1)
	{
		if (pipe(pipefd) == -1)
			return (perror("pipe"), check_close(prev_wr_fd), close(out_fd), i);
		cpid = fork();
		if (cpid == 0)
		{
			close(pipefd[0]);
			close(out_fd);
			child(prev_wr_fd, pipefd[1], params.commands[i], envp);
			clean_and_exit(params);
		}
		close(pipefd[1]);
		check_close(prev_wr_fd);
		if (cpid == -1)
			return (perror("fork"), close(pipefd[0]), close(out_fd), i);
		prev_wr_fd = pipefd[0];
	}
	spawn_last_child(params, prev_wr_fd, out_fd, envp);
	return (i);
}

int	pipex(t_execflow params, int in_fd, int out_fd, char *envp[])
{
	int	child_count;

	child_count = spawn_commands(params, in_fd, out_fd, envp);
	wait_childs(child_count);
	return (0);
}
