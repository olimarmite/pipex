/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olimarti <olimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:30:53 by olimarti          #+#    #+#             */
/*   Updated: 2023/05/05 21:28:54 by olimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <utils.h>
#include <structs.h>

#include <sys/wait.h>


// int	main(int argc, char *argv[], char *envp[])
// {
// 	int pid;

// 	if (argc < 2)
// 		return (0);
// 	pid = fork()
// 	if (pid == 0)
// 	{
// 		printf("HI from child (pid:%i)\n", pid);
// 	}
// 	//ft_execvpe(argv[1], argv + 1, envp);
// 	return (0);
// }


// int	child_logic(int pipefd[2])
// {
// 	char	*buf;

// 	close(pipefd[1]);
// 	while (read(pipefd[0], &buf, 1) > 0)
// 		write(STDOUT_FILENO, &buf, 1);
// 	write(STDOUT_FILENO, "\n", 1);
// 	close(pipefd[0]);
// 	return (errno);
// }

// int	main(int argc, char *argv[])
// {
// 	int	pipefd[2];
// 	int	cpid;
// 	int	cpid2;
// 	int	wstatus;

// 	if (argc < 2)
// 		return (1);
// 	if (pipe(pipefd) == -1) {
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	cpid = fork();
// 	if (cpid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (cpid == 0)
// 	{
// 		return (child_logic(pipefd));
// 	}
// 	else
// 	{
// 		close(pipefd[0]);
// 		printf("Hello World from parent (child pid:%i)\n", cpid);
// 		write(pipefd[1], argv[1], strlen(argv[1]));
// 		close(pipefd[1]);
// 		waitpid(cpid, &wstatus, 0);
// 		printf("\nChild Finished : exit Status %i", WEXITSTATUS(wstatus));
// 	}
// 	return (0);
// }


// int	main(int argc, char *argv[])
// {
// 	int pipefd[2];
// 	int	cpid;
// 	int	wstatus;

// 	if (argc < 2)
// 		return (1);

// 	if (pipe(pipefd) == -1) {
// 		perror("pipe");
// 		exit(EXIT_FAILURE);
// 	}
// 	cpid = fork();
// 	if (cpid == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (cpid == 0)
// 	{
// 		return (child_logic(pipefd));
// 	}
// 	else
// 	{
// 		close(pipefd[0]);
// 		printf("Hello World from parent (child pid:%i)\n", cpid);
// 		write(pipefd[1], argv[1], strlen(argv[1]));
// 		close(pipefd[1]);
// 		waitpid(cpid, &wstatus, 0);
// 		printf("\nChild Finished : exit Status %i", WEXITSTATUS(wstatus));
// 	}
// 	return (0);
// }




// void	child(t_command command, int fd_in, int fd_out)
// {
// 	dup2(fd_in, STDIN_FILENO);
// 	dup2(fd_out, STDOUT_FILENO);
// 	close(fd_in);
// 	close(fd_out);
// 	ft_execvpe(command.command, command.argv, command.envp);
// 	perror(command.command);
// 	exit(errno);
// }




// void	child(int fd_in, int fd_out, char *command, char *argv[], char *envp[])
// {
// 	dup2(fd_in, STDIN_FILENO);
// 	dup2(fd_out, STDOUT_FILENO);
// 	close(fd_in);
// 	close(fd_out);
// 	ft_execvpe(command, argv, envp);
// 	perror(command);
// 	exit(errno);
// }

// int	pipex(char **commands, int commands_count, int in_file, int out_file,  char *argv[], char *envp[])
// {
// 	int	pipefd[2];
// 	int	previous_write_fd;
// 	int	i;
// 	int	cpid;

// 	i = 0;
// 	previous_write_fd = in_file;
// 	while (i < commands_count - 1)
// 	{
// 		if (pipe(pipefd) == -1){
// 			perror("pipe"); //EXIT
// 		}
// 		cpid = fork();
// 		if (cpid == -1)
// 			perror("fork"); //EXIT
// 		if (cpid == 0)
// 		{
// 			close(pipefd[0]);
// 			//CHILD
// 			child(previous_write_fd, pipefd[1], commands[i], argv, envp);
// 		}
// 		else
// 		{
// 			//PARENT
// 			close(pipefd[1]);
// 			close(previous_write_fd);
// 			previous_write_fd = pipefd[0];
// 		}
// 		i++;
// 	}
// 	//last command
// 	cpid = fork();
// 	if (cpid == -1)
// 		perror("fork"); //EXIT
// 	if (cpid == 0)
// 	{
// 		child(previous_write_fd, out_file, commands[i], argv, envp);
// 	}

// 	close(previous_write_fd);
// 	while (i >= 0)
// 	{
// 		wait(NULL);
// 		i--;
// 	}
// 	return(0);
// }

// int main(int argc, char *argv[], char *envp[])
// {
// 	(void) argc;
// 	int in_fd;
// 	int out_fd;
// 	char *commands[] = {"caasdt", "dhashls", "ls", NULL};

// 	in_fd = open("/dev/stdin", O_RDONLY);
// 	out_fd = open("/dev/stdout", O_RDWR);
// 	pipex(commands, 3, in_fd, out_fd, argv, envp);
// 	close(in_fd);
// 	close(out_fd);
// 	// child(in_fd, out_fd, "cat", argv, envp);
// 	printf("FINISH\n");
// 	return (0);
// }



void	child(int fd_in, int fd_out, t_command command, char *envp[])
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd_in);
	close(fd_out);
	ft_execvpe(command.command_ptr, command.argv_ptr, envp);
	perror(command.command_ptr);
	exit(errno);
}

int	pipex(t_execflow params, int in_file, int out_file, char *envp[])
{
	int	pipefd[2];
	int	previous_write_fd;
	int	i;
	int	cpid;

	i = 0;
	previous_write_fd = in_file;
	while (i < params.command_count - 1)
	{
		if (pipe(pipefd) == -1){
			perror("pipe"); //EXIT
		}
		cpid = fork();
		if (cpid == -1)
			perror("fork"); //EXIT
		if (cpid == 0)
		{
			close(pipefd[0]);
			//CHILD
			child(previous_write_fd, pipefd[1], params.commands[i], envp);
		}
		else
		{
			//PARENT
			close(pipefd[1]);
			close(previous_write_fd);
			previous_write_fd = pipefd[0];
		}
		i++;
	}
	//last command
	cpid = fork();
	if (cpid == -1)
		perror("fork"); //EXIT
	if (cpid == 0)
	{
		child(previous_write_fd, out_file, params.commands[i], envp);
	}

	close(previous_write_fd);
	while (i >= 0)
	{
		wait(NULL);
		i--;
	}
	return(0);
}


int main(int argc, char *argv[], char *envp[])
{
	t_execflow params;
	int in_fd;
	int out_fd;

	if (parse_pipex_params(argv + 1, argc - 1, &params) == 0)
	{
		in_fd = open(params.input.filename, O_RDONLY);
		out_fd = open(params.output.filename, O_WRONLY | O_CREAT, 0666);
		if (in_fd == -1)
		{
			perror(params.input.filename);
			in_fd = open("/dev/null", O_RDONLY);
		}
		if (out_fd == -1)
		{
			perror(params.output.filename);
			out_fd = open("/dev/null", O_WRONLY);
		}
		pipex(params, in_fd, out_fd, envp);
		destroy_commands(&params.commands, params.command_count);
		close (in_fd);
		close (out_fd);
	}
	return (0);
}
