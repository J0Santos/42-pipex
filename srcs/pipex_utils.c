/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:06:33 by josantos          #+#    #+#             */
/*   Updated: 2021/09/08 16:03:53 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

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
