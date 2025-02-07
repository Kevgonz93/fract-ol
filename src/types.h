#include "../fract-ol.h"

typedef struct s_mouse
{
	int		x;
	int		y;
}	t_mouse;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		max_iter;
	int		width;
	int		height;
	double	zoom;
	double	x;
	double	y;
	int		color;
	t_mouse	*mouse;
	int		(*fractal)(struct s_fractol *fractol, int x, int y);
}	t_fractol;
