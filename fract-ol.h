#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "minilibx-linux/mlx.h"
# include "src/types.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

// FRACTALS.C

int			mandelbrot(t_fractol *fractol, int px, int py);
double		get_double(t_fractol *fractol, char *argv);
int			julia(t_fractol *fractol, int px, int py);

// HANDLES.C

int			zoom_handle(int key, t_fractol *fractol);
void		color_handle(int key, t_fractol *fractol);
int			move_handle(int key, t_fractol *fractol);
int			close_handle(t_fractol *fractol);
void		reset_fractol(t_fractol *fractol);

// UTILS.C

int			draw_fractol(t_fractol *fractol);
int			key_hook(int key, t_fractol *fractol);
int			ft_atoi(const char *str);
float		ft_atof(const char *str);

// INITIAL_SETTING.C

t_fractol	*fractol_init(char **fractal);

#endif
