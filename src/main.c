/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/03 15:16:28 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <libft.h>

char	*search_paths_env(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0 && envp[i][5] != 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}

int	main(int argc, char *argv[], char *envp[])
{
	char *paths;

	(void ) argc;
	paths = search_paths_env(envp);
	if (paths != 0)
	{
		printf("%s\n", paths);
	}
	execve("ping", argv, envp);
}
