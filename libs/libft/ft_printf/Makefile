# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ciclo <ciclo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 17:00:13 by ciclo             #+#    #+#              #
#    Updated: 2023/04/06 20:20:21 by ciclo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= printf.a
INCLUDE		:= include
LIBFT		:= libft
SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -Wall -Werror -Wextra -I
RM			:= rm -f
AR			:= ar rcs
val :=  valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

SANI := -fsanitize=address -g3

SRC_FILES	:=	 ft_print_int  ft_printf ft_printf_utils ft_printf_hex ft_printf_p

SRC	:= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ	:= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
#.SILENT:
ifndef verbose
.SILENT:
endif

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)
	echo "ft_printf compilando!"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

clean:
	$(RM) -rf $(OBJ_DIR)
	echo "ft_printf limpiando objetos!"

fclean:		clean
	$(RM) -f $(NAME)
	echo "ft_printf executable files cleaned!$(DEF_COLOR)"
	echo "libft executable files cleaned!"

cache:
	mkdir -p $(OBJ_DIR)

re:	fclean all
	echo "Cleaned and rebuilt everything for ft_printf!"

sanitize:
	$(CC) $(SANI) $(SRC) main.c -I $(INCLUDE)  -lft -o $(NAME)
	echo "Sanitize compilando!"

valgrind:
	$(val)	./libftprintf.a
	echo "\n valgind in use xd\n"

comp: all
	$(CC) test/main.c $(NAME)  -o main.o && ./main.o && rm -rf *.o
	echo "\n compilation done \n"

.PHONY:		all clean fclean re norm
