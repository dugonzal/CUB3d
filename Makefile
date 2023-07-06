NAME = cub3d

RY =	raycasting/raycasting\
		raycasting/print_text

FILES =	cub3d\
		read_map\
		utils\
		check_map\
		lch_mlx\
		key_hook\
		$(RY)

F = $(addprefix ./src/, $(FILES))
SRC = $(addsuffix .c, $(F))
OBJ = $(addsuffix .o, $(F))

CC = clang
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Wstring-compare -fsanitize=address -g3
MLXFLAGS = libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

.c.o: $(SRC)
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	@ $(MAKE) -C ./mlx/ 2> /dev/null
	@ mv ./mlx/libmlx.a .
	@ $(MAKE) -C ./Get_next_line/
	@ mv ./Get_next_line/get_next_line.a .
	@ $(CC) $(CFLAGS) $(OBJ) ./get_next_line.a $(MLXFLAGS) -o $(NAME)

clean:
	@ $(MAKE) -C ./mlx/ clean
	@ $(MAKE) -C ./Get_next_line/ clean
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) libmlx.a
	@ $(RM) get_next_line.a
	@ $(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re