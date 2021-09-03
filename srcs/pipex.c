/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:45:18 by josantos          #+#    #+#             */
/*   Updated: 2021/09/03 16:10:38 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	pipex(int f1, int f2)
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
}*/

int	main(int argc, char **argv, char **envp)
{
	int f1;
	int f2;
	char **cmd_path;
	int i = -1;
	
	argc = 0;
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC);
	cmd_path = get_path(envp);
	while (cmd_path[++i])
		printf("%s\n", cmd_path[i]);
/*	pipex(f1, f2, path);
}

void	child_process(
*/
}
