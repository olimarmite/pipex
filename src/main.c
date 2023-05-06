/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/06 21:00:27 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <structs.h>

#include <sys/wait.h>

void	child(int fd_in, int fd_out, t_command command, char *envp[], t_execflow params)
{
	if (fd_in != -1)
	{
		close(fd_in);
		dup2(fd_in, STDIN_FILENO);
	}
	if (fd_in != -1)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	if (fd_in != -1 && fd_out != -1)
	{
		ft_execvpe(command.command_ptr, command.argv_ptr, envp);
		perror(command.command_ptr);
	}
	destroy_commands(&params.commands, params.command_count);
	exit(errno);
}

void	wait_childs(int childs_count)
{
	while (childs_count >= 0)
	{
		wait(NULL);
		childs_count--;
	}
}

void check_close(int fd)
{
	if (fd != -1)
		close(fd);
}

int	pipex(t_execflow params, int in_file, int out_file, char *envp[])
{
	int	pipefd[2];
	int	previous_write_fd;
	int	i;
	int	cpid;

	i = 0;
	previous_write_fd = in_file;
	while (i < params.command_count - 1)
	{
		if (pipe(pipefd) == -1){
			perror("pipe"); //EXIT
			check_close(previous_write_fd);
			close(out_file);
			return (-1);
		}
		cpid = fork();
		if (cpid == -1)
		{
			perror("fork"); //EXIT
			close(pipefd[0]);
			close(pipefd[1]);
			check_close(previous_write_fd);
			close(out_file);
			return (-1);
		}
		if (cpid == 0)
		{
			close(pipefd[0]);
			//CHILD
			child(previous_write_fd, pipefd[1], params.commands[i], envp, params);
		}
		else
		{
			//PARENT
			close(pipefd[1]);
			check_close(previous_write_fd);
			previous_write_fd = pipefd[0];
		}
		i++;
	}
	cpid = fork();
	if (cpid == -1)
		perror("fork"); //EXIT
	if (cpid == 0)
		child(previous_write_fd, out_file, params.commands[i], envp, params);
	check_close(previous_write_fd);
	close(out_file);
	wait_childs(i);
	return(0);
}

int main(int argc, char *argv[], char *envp[])
{
	t_execflow params;
	int in_fd;
	int out_fd;

	// if (argc != 5)
	if (argc < 5)
	{
		errno = EINVAL;
		perror("pipex");
		return(1);
	}

	if (parse_pipex_params(argv + 1, argc - 1, &params) == 0)
	{
		in_fd = open(params.input.filename, O_RDONLY);
		out_fd = open(params.output.filename, O_WRONLY | O_CREAT, 0644);
		if (in_fd == -1)
		{
			perror(params.input.filename);
		}
		if (out_fd == -1)
		{
			perror(params.output.filename);
		}
		pipex(params, in_fd, out_fd, envp);
		destroy_commands(&params.commands, params.command_count);
	}
	return (0);
}
