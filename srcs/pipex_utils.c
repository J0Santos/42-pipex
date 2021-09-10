/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:06:33 by josantos          #+#    #+#             */
/*   Updated: 2021/09/10 17:36:09 by josantos         ###   ########.fr       */
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

char	**get_path(char **envp)
{
	char	**cmd_path;
	int i;
	bool trim;

	cmd_path = NULL;
	i = -1;
	trim = true;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			cmd_path = ft_split(envp[i], ':');
	if (trim == true)
	{
		if (ft_strncmp(cmd_path[0], "PATH=", 5) == 0)
			cmd_path[0] = ft_substr(cmd_path[0], 5, ft_strlen(cmd_path[0])- 5);
		trim = false;
	}
	i = -1;
	while (cmd_path[++i])
		cmd_path[i] = ft_strjoin(cmd_path[i], "/");
	return (cmd_path);
}

char	*update_path(t_pipex *p)
{
	int i;

	i = -1;
	while (p->cmd_paths[++i])
	{
		p->cmd_paths[i] = ft_strjoin(p->cmd_paths[i], p->cmd[0]);
		check_access(p->cmd_paths[i]);
		if (access(p->cmd_paths[i], X_OK) == -1)
		{
			free(p->cmd_paths[i]);
			ft_error("Command not found");
		}
		else
			p->correct_path = p->cmd_paths[i];
	}
		i = -1;
		while (p->cmd_paths[++i])
			free(p->cmd_paths[i]);
		return (p->correct_path);
}
