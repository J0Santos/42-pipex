/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:45:18 by josantos          #+#    #+#             */
/*   Updated: 2021/09/08 16:03:48 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char **cmd_path, char **argv)
{
	int		fd[2];
	pid_t	pid;
	int pipe_checker;

	pipe_checker = pipe(fd);
	if (pipe_checker < 1)
		ft_error("Error creating pipe");
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	if (!pid)
		child_process(fd,  cmd_path, argv);
	waitpid(pid, NULL, 0);
	parent_process(fd, cmd_path, argv);
}

int	main(int argc, char **argv, char **envp)
{
	int f1;
	int f2;
	char **cmd_path;
	int i = -1;
	
	if (argc < 5)
		ft_error("Too few arguments, must be <./pipex file1 cmd1 cmd2 file2>")
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
	cmd_path = get_path(envp);
	pipex(f1, f2, cmd_path, argv);
}

void	child_process(int *fd, char **path, char **argv)
{
	char **cmd;

	cmd = ft_split(argv[2], ' ');
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	execve(path, cmd, envp
}
