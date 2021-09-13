/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:57:51 by josantos          #+#    #+#             */
/*   Updated: 2021/09/13 11:27:38 by josantos         ###   ########.fr       */
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
	char *correct_path;
}	t_pipex;


void	init_val(t_pipex *p, char	**argv, char **envp);
int		ft_error(char *message);
char	**get_path(char **envp);
char	*trim(char **line, char *cut);
char	*update_path(t_pipex *p);
int	check_access(char *path);

void	child_process(int *fd, t_pipex *p);
void	parent_process(int *fd, t_pipex *p);

#endif
