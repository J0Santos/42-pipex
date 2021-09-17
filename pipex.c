/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:45:18 by josantos          #+#    #+#             */
/*   Updated: 2021/09/17 11:30:31 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex *p)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
	{
		free_val(p);
		ft_error("Error creating pipe");
	}
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	if (!pid)
		child_process(fd, p);
	waitpid(pid, NULL, 0);
	parent_process(fd, p);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	if (argc < 5)
		ft_error("Error: Execution must be: ./pipex file1 cmd1 cmd2 file2");
	init_val(&p, argv, envp);
	pipex(&p);
	free_val(&p);
}
