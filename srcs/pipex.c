/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:45:18 by josantos          #+#    #+#             */
/*   Updated: 2021/09/10 17:36:07 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex *p)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) < 0)
		ft_error("Error creating pipe");
	pid = fork();
	if (pid < 0)
		return (perror("Fork: "));
	if (!pid)
		child_process(fd, p);
	waitpid(pid, NULL, 0);
	parent_process(fd, p);
}

void	child_process(int *fd, t_pipex *p)
{
	int in;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	in = open(p->argv[1], O_RDONLY);
	if (in < 0)
		ft_error("Error opening infile");
	dup2(in, 0);
	p->cmd = ft_split(p->argv[2], ' ');
	p->correct_path = update_path(p);
	execve(p->correct_path, p->cmd, p->envp);
}
/*
void	parent_process(int *fd, t_pipex *p)
{
	int out;

	dup2(
	out = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
	if (out < 0)
		ft_error("Error opening outfile");
}
*/
int	main(int argc, char **argv, char **envp)
{
	t_pipex p;
	
	if (argc < 5)
		ft_error("Usage must be: ./pipex file1 cmd1 cmd2 file2");
	init_val(&p, argv, envp);
	pipex(&p);
}
