/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:06:33 by josantos          #+#    #+#             */
/*   Updated: 2021/09/16 16:22:09 by josantos         ###   ########.fr       */
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

/*
char	**get_path(char **envp)
{
	char	**cmd_path;
	char	**path_builder;
	int i;

	i = -1;
	path_builder = NULL;
	cmd_path = NULL;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			path_builder = ft_split(envp[i], ':');
	if (ft_strncmp(path_builder[0], "PATH=", 5) == 0)
		path_builder[0] += 5;
	i = 0;
	while (path_builder && path_builder[i])
		i++;
	cmd_path = malloc((i + 1) * sizeof(char *));
	if (!cmd_path)
		return (NULL);
	cmd_path[i] = 0;
	i = -1;
	while (path_builder[++i])
	{
		cmd_path[i] = ft_strjoin(path_builder[i], "/");
		free(path_builder[i]);
	}
	return (cmd_path);
}
*/
