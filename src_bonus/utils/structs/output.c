/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:06 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/08 13:45:11 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

t_output	output(int append, char *filename)
{
	t_output	result;

	result.append = append;
	result.filename = filename;
	return (result);
}
