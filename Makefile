NAME = fractol

SRC = ${wildcard *.c}
SRC_SRC = ${wildcard src/*.c}
SRC_ALL = $(SRC) $(SRC_SRC)
OBJ = $(SRC_ALL:.c=.o)

MLX_DIR = minilibx
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

X11_FLAGS = -I/opt/X11/include -L/opt/X11/lib -lX11 -lXext

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) -I$(MLX_DIR) $(X11_FLAGS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c fract-ol.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I/opt/X11/include -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
