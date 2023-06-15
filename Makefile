# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 12:31:04 by Dugonzal          #+#    #+#              #
#    Updated: 2023/06/15 12:40:39 by Dugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3d

CC		:= clang -g3

R		:= rm -rf

CFLAGS	:= -Wall -Wextra -Werror

SHELL	:= /bin/zsh

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) src/cub3d.c && ./cub3d
clean:
	$(R) $(NAME)
fclean: clean

re: fclean all
