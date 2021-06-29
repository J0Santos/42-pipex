/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:00:12 by josantos          #+#    #+#             */
/*   Updated: 2021/06/29 20:13:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

void	call_child(char **argv, char **envp, int fd)
{
	int i;
	char **path;

	i = 0;
	path = get_path(envp);
	execve(
}

int	main(int argc, char **argv, char **envp)
{
	int fd[argc - 3][2];
	int i;
	int pid;

	i = 2;
	while (++i < argc)
	{
		if (pipe(fd) == -1)
			ft_error("Error with creating pipe");
		if (open(argv[1], O_RDONLY) == -1)
			ft_error("Error opening file");
		

		pid = fork();
		if (pid < 0)
			ft_error("Error with fork");
		if (pid == 0)
			call_child(argv, envp, fd);
		else
			call_parent
	}
}
