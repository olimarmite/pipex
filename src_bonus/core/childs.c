/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:52:06 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/09 01:12:21 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>

#include <sys/wait.h>

void	child(int fd_in, int fd_out, t_command command, char *envp[])
{
	if (fd_in != -1)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != -1)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
	if (fd_in != -1 && fd_out != -1)
	{
		if (command.command_ptr == NULL)
			ft_putstr_fd("Command '' not found\n", STDERR_FILENO);
		else
		{
			ft_execvpe(command.command_ptr, command.raw_data, envp);
			perror(command.command_ptr);
		}
	}
}

void	wait_childs(int childs_count)
{
	while (childs_count >= 0)
	{
		wait(NULL);
		childs_count--;
	}
}
