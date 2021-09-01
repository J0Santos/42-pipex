/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:45:18 by josantos          #+#    #+#             */
/*   Updated: 2021/09/01 15:26:36 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2)
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
		child_process(fd, path);
	waitpid(pid, NULL, 0);
	parent_process();
}

int	main(int argc, char **argv, char **envp)
{
	int f1;
	int f2;
	char *

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
	path = get_env(envp);
	pipex(f1, f2, path);
}

void	child_process(

