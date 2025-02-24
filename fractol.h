#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx/mlx.h"
# include "aux/aux.h"
# include "src/types.h"
# include "printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// FRACT-OL.C

t_fractol	*fractol_init(char **fractal);

// FRACTALS.C

int			tricorn(t_fractol *fractol, int px, int py);
int			mandelbrot(t_fractol *fractol, int px, int py);
int			julia(t_fractol *fractol, int px, int py);

// HANDLES.C

void		color_handle(int key, t_fractol *fractol);
int			zoom_handle(int key, t_fractol *fractol);
int			move_handle(int key, t_fractol *fractol);
int			close_handle(t_fractol *fractol);
void		reset_fractol(t_fractol *fractol);

// UTILS.C

void		next_color(t_fractol *fractol);
void		reasigning_colors(t_colors *colors);
void		put_pixel(t_image *image, int x, int y, int color);
int			draw_fractol(t_fractol *fractol);
void		reset_fractol(t_fractol *fractol);

// INITIAL_SETTING.C

void		init_data(t_fractol *fractol, char **argv);
t_image		init_image(t_fractol *fractol, char **argv);
void		init_mouse(t_fractol *fractol);

// HOOKS.C

int			key_hook(int key, t_fractol *fractol);
int			mouse_hook(int key, int x, int y, t_fractol *fractol);

#endif
