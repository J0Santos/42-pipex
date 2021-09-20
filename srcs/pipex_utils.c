/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:06:33 by josantos          #+#    #+#             */
/*   Updated: 2021/09/20 16:24:00 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	init_val(t_pipex *p, char **argv, char **envp)
{
	p->envp = envp;
	p->argv = argv;
	p->cmd_paths = get_path(envp);
	p->cmd = NULL;
}

void	free_val(t_pipex *p)
{
	if (p->envp)
		free_dpointer(p->envp);
	if (p->argv)
		free_dpointer(p->argv);
	if (p->cmd_paths)
		free_dpointer(p->cmd_paths);
	if (p->cmd)
		free_dpointer(p->cmd);
	if (p->correct_path)
		free(p->correct_path);
}

char	**get_path(char **envp)
{
	char	**cmd_path;
	char	**temp;
	int		i;

	i = -1;
	temp = NULL;
	while (envp[++i] && temp == NULL)
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			temp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (temp[i])
		i++;
	cmd_path = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cmd_path)
		return (NULL);
	i = -1;
	while (temp[++i])
	{
		cmd_path[i] = ft_strjoin(temp[i], "/");
		free(temp[i]);
	}
	free(temp);
	return (cmd_path);
}
