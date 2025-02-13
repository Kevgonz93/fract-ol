#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include "aux/aux.h"
# include "src/types.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// FRACTALS.C

int			mandelbrot(t_fractol *fractol, int px, int py);
// int			julia(t_fractol *fractol, int px, int py);

// HANDLES.C

int			zoom_handle(int key, t_fractol *fractol);
void		color_handle(int key, t_fractol *fractol);
// int			move_handle(int key, t_fractol *fractol);
int			close_handle(t_fractol *fractol);
void		reset_fractol(t_fractol *fractol);

// UTILS.C

int			key_hook(int key, t_fractol *fractol);
int			draw_fractol(t_fractol *fractol);
void		put_pixel(t_image *image, int x, int y, int color);
int			mouse_hook(int key, t_fractol *fractol);

// INITIAL_SETTING.C

t_fractol	*fractol_init(char **fractal);

#endif
