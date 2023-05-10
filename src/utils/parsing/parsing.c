/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:53:03 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/10 15:32:33 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>

t_input	parse_input(char **args)
{
	return (input(file, args[0], NULL));
}

int	parse_command(char *str, t_command *result)
{
	char	**splited;

	if (str == NULL)
		return (1);
	splited = ft_split(str, ' ');
	if (splited == NULL)
		return (1);
	*result = command(splited[0], splited + 1, splited);
	return (0);
}

int	parse_commands(char **args, int command_count, t_command **commands_out)
{
	int	i;

	i = 0;
	*commands_out = malloc(sizeof(t_command) * command_count);
	if (*commands_out == NULL)
		return (1);
	while (i < command_count)
	{
		if (parse_command(args[i], *commands_out + i))
		{
			return (destroy_commands(commands_out, i), 1);
		}
		i++;
	}
	return (0);
}

void	destroy_commands(t_command **command_lst, int command_count)
{
	int	i;
	int	j;

	i = 0;
	if (command_lst == NULL)
		return ;
	while (i < command_count)
	{
		j = 0;
		while ((*command_lst)[i].raw_data[j])
		{
			free((*command_lst)[i].raw_data[j]);
			j++;
		}
		free((*command_lst)[i].raw_data);
		i++;
	}
	free(*command_lst);
	*command_lst = NULL;
}

int	parse_pipex_params(char *argv[], int argc, t_execflow *params_out)
{
	t_execflow	params;
	int			i;

	if (argc < 2)
		return (1);
	params.input = parse_input(argv);
	i = (params.input.type == here_doc) + 1;
	params.command_count = argc - i - 1;
	if (parse_commands(argv + i, params.command_count, &params.commands) == 1)
		return (2);
	if (params.command_count >= 0)
		params.output = output(params.input.type == here_doc, argv[argc - 1]);
	else
		params.output = output(params.input.type == file, NULL);
	*params_out = params;
	return (0);
}
