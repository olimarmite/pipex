/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:52:06 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/08 12:52:12 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>
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
		ft_execvpe(command.command_ptr, command.argv_ptr, envp);
		perror(command.command_ptr);
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
