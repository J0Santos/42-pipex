/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_access.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 16:51:09 by josantos          #+#    #+#             */
/*   Updated: 2021/09/10 17:36:05 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_access(char *path)
{
if (access(path, X_OK) == 0)
			return ;
	free(path);
	ft_error("Command not found");
}

/*Colocar error a funcionar so quando todas as hipoteses de p->cmd_path forem revistas*/
