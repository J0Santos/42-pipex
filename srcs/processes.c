/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:04:24 by josantos          #+#    #+#             */
/*   Updated: 2021/09/15 17:38:17 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, t_pipex *p)
{
	int in;
	int a = -1;;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	in = open(p->argv[1], O_RDONLY);
	if (in < 0)
		ft_error("Error opening infile");
	dup2(in, 0);
	p->cmd = ft_split(p->argv[2], ' ');
	while (p->cmd_paths[++a])
	{	
		p->correct_path = ft_strjoin(p->cmd_paths[a], p->cmd[0]);
		execve(p->correct_path, p->cmd, p->envp);
	}
	free(p->correct_path);
	ft_error("1st command not found");
}

void	parent_process(int *fd, t_pipex *p)
{
	int out;
	int a = -1;

	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	out = open(p->argv[4], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IROTH);
	if (out < 0)
		ft_error("Error opening outfile");
	dup2(out, 1);
	p->cmd = ft_split(p->argv[3], ' ');
	while (p->cmd_paths[++a])
	{	
		p->correct_path = ft_strjoin(p->cmd_paths[a], p->cmd[0]);
		execve(p->correct_path, p->cmd, p->envp);
	}
	free(p->correct_path);
	ft_error("2nd command not found");
}
