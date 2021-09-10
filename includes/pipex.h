/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:57:51 by josantos          #+#    #+#             */
/*   Updated: 2021/09/10 13:58:23 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
 # define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>


typedef struct s_pipex
{
	char **envp;
	char **argv;
	char **cmd_paths;
	char **cmd;
}	t_pipex;


int		ft_error(char *message);
char	**get_path(char **envp);
char	*trim(char **line, char *cut);

void	child_process(int *fd, char **path, char **argv);
void	parent_process(int *fd, char **path, char

#endif
