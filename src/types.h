#include "../fract-ol.h"

typedef struct s_color
{
	int	index;
	int	color;
}	t_color;

typedef struct s_colors
{
	t_color	color_1;
	t_color	color_2;
	t_color	color_3;
	t_color	color_4;
	t_color	color_5;
	t_color	color_6;
	t_color	color_7;
	t_color	color_8;
	t_color	color_9;
	t_color	color_10;
}	t_colors;

typedef struct s_mouse
{
	int		x;
	int		y;
}	t_mouse;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			max_iter;
	int			width;
	int			height;
	double		zoom;
	double		x;
	double		y;
	t_colors	*colors;
	t_color		*current_color;
	t_mouse		*mouse;
	int			(*fractal)(struct s_fractol *fractol, int x, int y);
}	t_fractol;
