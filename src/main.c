/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/15 13:28:49 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_execflow	params;
	int			in_fd;
	int			out_fd;

	if (argc != 5)
		errno = EINVAL;
	else if (parse_pipex_params(argv + 1, argc - 1, &params) == 0)
	{
		if (params.command_count < 2)
			errno = EINVAL;
		else
		{
			in_fd = get_in_fd(&params);
			out_fd = get_out_fd(params);
			if (in_fd == -1)
				perror(params.input.filename);
			if (out_fd == -1)
				perror(params.output.filename);
			pipex(params, in_fd, out_fd, envp);
			clean_tmp_files(&params);
			destroy_commands(&params.commands, params.command_count);
			return (0);
		}
	}
	return (perror("pipex"), 1);
}
