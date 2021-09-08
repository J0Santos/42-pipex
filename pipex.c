/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:00:12 by josantos          #+#    #+#             */
/*   Updated: 2021/09/08 15:48:28 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;
	int i;

	i = 2;
	if (argc < 5)
		ft_error
	while (*argv[i++] && i < argc - 2)
	{
		if (pipe(fd) == -1)
			ft_error("Error creating pipe");
		pid = fork();
		if (pid < 0)
			ft_error("Error with fork");
		if (pid == 0)
			call_child(fd, argv, envp);
		else
			call_parent(fd, argv, envp);
		wait(NULL);
	}
}

