/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/15 15:36:19 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *envp[])
{
	t_execflow	params;

	if (argc < 5)
		errno = EINVAL;
	else if (parse_pipex_params(argv + 1, argc - 1, &params) == 0)
	{
		if (params.command_count >= 2)
		{
			pipex(params, envp);
			destroy_commands(&params.commands, params.command_count);
			errno = EINVAL;
			return (0);
		}
		destroy_commands(&params.commands, params.command_count);
			errno = EINVAL;
	}
	return (perror("pipex"), 1);
}
