# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 12:31:04 by Dugonzal          #+#    #+#              #
#    Updated: 2023/06/15 18:36:32 by Dugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3d
CC			:= clang -g3
R			:= rm -rf
CFLAGS		:= -Wall -Wextra -Werror
SHELL		:= /bin/zsh
SRC_DIR		:= src/
OBJ_DIR		:= obj/
MLX_CF		:= -framework OpenGL -framework AppKit
MLX_PATH 	:= ./libs/minilibx_macos
val 		:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANI 		:= -fsanitize=address -g3

SRC_FILES	:= cub3d

SRC			:= $(addprefix $(SRC_DIR), $(addsuffix, .c $(SRC_FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix, .c $(SRC_FILES)))

ifeq ($(shell uname), Linux)
$(NAME): MLX_CF	= -L./libs/mlx_linux -lmlx_Linux -lXext -lX11
$(NAME): MLX_PATH = ./libs/mlx_linux 
endif

$(NAME): $(OBJ)


$(OBJ_DIR):%.o $(SRC_DIR) %.c 
	if [[ ! -d "libs/libft" ]]; then git clone https://github.com/dugonzal/libft.git libs/libft; fi
	$(CC) 


#	$(CC) $(CFLAGS) -o $(NAME) $(SRC) && ./cub3d

all: $(NAME)

clean:
	$(R) $(NAME)

fclean: clean

re: fclean all
