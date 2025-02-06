#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-macos/mlx.h"
# include "src/types.h"
# include <stdlib.h>
# include <stdio.h>

// FRACTOL.C

int		key_hook(int key, t_fractol *fractol);
void	create_image(t_fractol *fractol);

// HANDLES.C

int		zoom_handle(int key, t_fractol *fractol);
int		close_handle(t_fractol *fractol);
int		move_handle(int key, t_fractol *fractol);

// UTILS.C

int		draw_fractol(t_fractol *fractol);
int		mouse_click(int button, int x, int y, t_fractol *fractol);
int		mouse_move(int x, int y, t_fractol *fractol);

#endif
