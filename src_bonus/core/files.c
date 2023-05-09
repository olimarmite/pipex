/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:39:37 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/09 01:12:21 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>
#include <structs.h>

#include <sys/wait.h>

int	get_in_fd(t_execflow params)
{
	if (params.input.type == here_doc)
		return (heredoc(params.input.limiter));
	else
		return (open(params.input.filename, O_RDONLY));
}

int	get_out_fd(t_execflow params)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (params.output.append == 0)
		flags |= O_TRUNC;
	else
		flags |= O_APPEND;
	return (open(params.output.filename, flags, 0644));
}
