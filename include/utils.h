/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:16:59 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/05 19:23:55 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <libft.h>
# include <string.h>
# include <errno.h>
# include <structs.h>

char	*get_paths_env(char *envp[]);
char	**parse_paths(char *path_str);
void	ft_strcpy(char *dst, char *src);
char	*join_path(char *dir, char *prog_name);
char	*get_command_path(char *file, char *envp[]);
int		ft_execvpe(char *file, char *argv[], char *envp[]);

int		parse_pipex_params(char *argv[], int argc, t_execflow *params_out);
void	destroy_commands(t_command **command_lst, int command_count);

#endif
