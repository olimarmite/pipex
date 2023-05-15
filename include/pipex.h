/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:16:59 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/15 15:25:49 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
char	*join_path(char *dir, char *prog_name);
char	*get_command_path(char *file, char *envp[]);
int		ft_execvpe(char *file, char *argv[], char *envp[]);

int		parse_pipex_params(char *argv[], int argc, t_execflow *params_out);
void	destroy_commands(t_command **command_lst, int command_count);

int		read_write(char *limiter, int in_fd, int out_fd);
int		heredoc_pipe(char *limiter);
int		heredoc_file(char *limiter, char **filename);
int		heredoc(char *limiter, char **filename);

void	safe_close(int fd);
void	child(int fd_in, int fd_out, t_command command, char *envp[]);
void	wait_childs(int childs_count);
int		get_out_fd(t_execflow params);
int		get_in_fd(t_execflow *params);

int		ft_strcpy(char *dst, char *src);
void	clean_tmp_files(t_execflow *params);

void	clean_and_exit(t_execflow params);
// int		pipex(t_execflow params, int in_fd, int out_fd, char *envp[]);
int		pipex(t_execflow params, char *envp[]);
void	spawn_last_child(t_execflow params, int prev_wr_fd, int out_fd,
			char *envp[]);
int		spawn_commands(t_execflow params, int prev_wr_fd, int out_fd,
			char *envp[]);

#endif
