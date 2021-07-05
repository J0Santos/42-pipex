/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 19:06:33 by josantos          #+#    #+#             */
/*   Updated: 2021/07/05 18:08:08 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_redirect(char **argv, int argc)
{
	int open_fd;

	open_fd = open(argv[argc - 1], O_CREAT | O_TRUNC);
	dup2(open_fd, STDOUT_FILENO);
	close(open_fd);
}
