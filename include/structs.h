/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:32:09 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/06 21:06:38 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdlib.h>

typedef enum e_input_type {
	file,
	here_doc
}	t_input_type;

typedef struct s_command
{
	char	*command_ptr;
	char	**argv_ptr;
	char	**raw_data;
}	t_command;

typedef struct s_input
{
	t_input_type	type;
	char			*filename;
	char			*limiter;
}	t_input;

typedef struct s_output
{
	int		append;
	char	*filename;
}	t_output;

typedef struct s_execflow
{
	t_input		input;
	t_output	output;
	t_command	*commands;
	int			command_count;
}	t_execflow;

t_command	command(char *command_ptr, char **argv_ptr, char **raw_data);
t_input		input(t_input_type type, char *filename, char *limiter);
t_output	output(int append, char *filename);

#endif
