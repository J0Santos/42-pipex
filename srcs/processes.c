/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:04:24 by josantos          #+#    #+#             */
/*   Updated: 2021/09/13 16:31:48 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	parent_process(int *fd, t_pipex *p)
{
	int out;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	out = open(p->argv[4], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (out < 0)
		ft_error("Error opening outfile");
	dup2(out, 1);
	p->cmd = ft_split(p->argv[3], ' ');
	p->correct_path = update_path(p);
	execve(p->correct_path, p->cmd, p->envp);
}
