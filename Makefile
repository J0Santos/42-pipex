# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josantos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/29 14:02:55 by josantos          #+#    #+#              #
#    Updated: 2021/09/07 18:36:38 by josantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = pipex
SRCS = srcs/pipex_utils.c \
	   srcs/pipex.c
OBJS = $(SRCS:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror -g
INC = -Iincludes -Llibft -lft

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Iincludes -c -o $@ $<

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(FLAGS) $(INCS) ./libft/libft.a $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: clean all fclean re
