NAME = fractol

SRC = ${wildcard *.c}
SRC_AUX = ${wildcard aux/*.c}
SRC_SRC = ${wildcard src/*.c}
SRC_ALL = $(SRC) $(SRC_SRC) $(SRC_AUX) $(SRC_PRINTF)
OBJ = $(SRC_ALL:.c=.o)

OS = $(shell uname)

LIBPRINTF_DIR = ft_printf
LIBPRINTF = $(LIBPRINTF_DIR)/libftprintf.a

ifeq ($(OS), Darwin)
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
	X11_FLAGS = -I/opt/X11/include -L/opt/X11/lib -lX11 -lXext
else
	MLX_DIR = minilibx-linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd
	X11_FLAGS =
endif

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBPRINTF) $(NAME)

$(LIBPRINTF):
	$(MAKE) -C $(LIBPRINTF_DIR)

$(NAME): $(OBJ)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBPRINTF) -I$(MLX_DIR) $(X11_FLAGS) $(MLX_FLAGS) -o $(NAME) -Lft_printf -lftprintf
	make clean

%.o: %.c fract-ol.h
	$(CC) $(CFLAGS) -I$(MLX_DIR) -I/opt/X11/include -c $< -o $@

clean:
	$(MAKE) -C $(LIBPRINTF_DIR) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBPRINTF_DIR) fclean
	rm -f $(NAME)
	make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re
