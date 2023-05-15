/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:17:33 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/15 15:37:35 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>
#include <sys/wait.h>

void	clean_and_exit(t_execflow params)
{
	destroy_commands(&params.commands, params.command_count);
	if (params.input.type == here_doc && params.input.filename != NULL)
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
		safe_close(prev_wr_fd);
		safe_close(out_fd);
		clean_and_exit(params);
	}
	safe_close(out_fd);
	safe_close(prev_wr_fd);
	safe_close(out_fd);
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
			return (perror("pipe"), safe_close(prev_wr_fd),
				safe_close(out_fd), i);
		cpid = fork();
		if (cpid == 0)
		{
			close(pipefd[0]);
			safe_close(out_fd);
			child(prev_wr_fd, pipefd[1], params.commands[i], envp);
			clean_and_exit(params);
		}
		close(pipefd[1]);
		safe_close(prev_wr_fd);
		if (cpid == -1)
			return (perror("fork"), close(pipefd[0]), safe_close(out_fd), i);
		prev_wr_fd = pipefd[0];
	}
	return (spawn_last_child(params, prev_wr_fd, out_fd, envp), i);
}

int	pipex(t_execflow params, char *envp[])
{
	int	child_count;
	int	in_fd;
	int	out_fd;

	in_fd = get_in_fd(&params);
	out_fd = get_out_fd(params);
	if (in_fd == -1)
		perror(params.input.filename);
	if (out_fd == -1)
		perror(params.output.filename);
	child_count = spawn_commands(params, in_fd, out_fd, envp);
	wait_childs(child_count);
	clean_tmp_files(&params);
	return (0);
}
