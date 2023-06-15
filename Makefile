# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dugonzal <dugonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 12:31:04 by Dugonzal          #+#    #+#              #
#    Updated: 2023/06/15 20:59:13 by Dugonzal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= cub3d
C			:= clang -g3
R			:= rm -rf
CFLAGS		:= -Wall -Wextra -Werror
SHELL		:= /bin/zsh
SRC_DIR		:= src/
OBJ_DIR		:= obj/
MLX_CF		:= -framework OpenGL -framework AppKit
MLX_PATH 	:= libs/minilibx_macos/
val 		:=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
SANI 		:= -fsanitize=address

SRC_FILES	:= cub3d

SRC			:= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ			:= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

ifeq ($(shell uname), Linux)
MLX_CF	:= -Llibs/mlx_linux -lmlx_Linux -lXext -lX11
MLX_PATH := libs/mlx_linux/
endif

.SILENT:

$(NAME): $(OBJ)
	make -C $(MLX_PATH) 2> /dev/null
	echo $(MLX_PATH)
	cp -r $(MLX_PATH)libmlx.a libs/bin/ 
	$(CC) $(SANI) $(CFLAGS) $(MLX_CF) $(OBJ) -lm libs/bin/*.a -o $(NAME)
	echo "\033[32m[✔ ] $(NAME) created game cub3d\033[0m"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p libs/bin
	mkdir -p $(OBJ_DIR)
	# si no tienes cli-git instalado, instala git y ejecuta el comando git clone https://github.com/dugonzal/libft
	if [[ ! -d "libs/libft" ]]; then gh repo clone libft && mv libft libs/  ; fi
	make -C libs/libft && cp -r libs/libft/libft.a libs/bin/
	echo "\033[32m[$<]\033[0m $(NAME) created \033[0m"
	$(C) $(CFLAGS) -c $< -o $@
	printf "$<"

all: $(NAME)

clean:
	$(R) $(NAME)
	make -C libs/libft clean
fclean: clean
	$(R) $(OBJ_DIR) $(NAME) libs/bin
	make -C $(MLX_PATH) clean
	make -C libs/libft fclean
re: fclean all
