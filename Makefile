NAME = fractol

SRC = ${wildcard *.c}
SRC_SRC = ${wildcard src/*.c}
SRC_ALL = $(SRC) $(SRC_SRC)
OBJ = $(SRC_ALL:.c=.o)

MLX_MAC = minilibx-macos
MLX_macFLAGS = -L$(MLX_MAC) -lmlx -framework OpenGL -framework AppKit

MLX_LINUX = minilibx-linux
MLX_linFLAGS = -L$(MLX_LINUX) -lmlx -framework OpenGL -framework AppKit

X11_FLAGS = -I/opt/X11/include -L/opt/X11/lib -lX11 -lXext

CC = cc
CFLAGS = -Wall -Wextra -Werror

mac: $(NAME)

$(NAME): $(OBJ)
	make mac -C $(MLX_MAC)
	$(CC) $(CFLAGS) $(OBJ) -I$(MLX_MAC) $(X11_FLAGS) $(MLX_macFLAGS) -o $(NAME)

linux: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_LINUX)
	$(CC) $(CFLAGS) $(OBJ) -I$(MLX_LINUX) $(X11_FLAGS) $(MLX_linFLAGS) -o $(NAME)

%.o: %.c fract-ol.h
	$(CC) $(CFLAGS) -I$(MLX_MAC) -I/opt/X11/include -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_MAC) clean

re: fclean all

.PHONY: all clean fclean re
