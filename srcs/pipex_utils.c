/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:06:33 by josantos          #+#    #+#             */
/*   Updated: 2021/09/07 18:36:36 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**get_path(char **envp)
{
	char	**cmd_path;
	int i;

	cmd_path = NULL;
	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			cmd_path = ft_split(envp[i], ':');
			break ;
		}
	i = -1;
	while (cmd_path[++i])
	{
		ft_strtrim(cmd_path[i], "PATH");
		ft_strjoin(cmd_path[i], "/");
	}
	return (cmd_path);
}
