/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josantos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:57:51 by josantos          #+#    #+#             */
/*   Updated: 2021/09/03 13:40:08 by josantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
 # define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_error(char *message);
char	**get_path(char **envp);

#endif
