/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 00:35:34 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/08 13:45:18 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

t_command	command(char *command_ptr, char **argv_ptr, char **raw_data)
{
	t_command	result;

	result.command_ptr = command_ptr;
	result.argv_ptr = argv_ptr;
	result.raw_data = raw_data;
	return (result);
}
