/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:18:27 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/08 13:45:47 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>

t_input	input(t_input_type type, char *filename, char *limiter)
{
	t_input	result;

	result.type = type;
	result.filename = filename;
	result.limiter = limiter;
	return (result);
}
