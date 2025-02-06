#include "../fractol-mac.h"
#include "../fractol-linux.h"

typedef struct s_mouse
{
	int		x;
	int		y;
}	t_mouse;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	double	zoom;
	double	x;
	double	y;
	int		width;
	int		height;
	int		color;
	int		(*fractal)(struct s_fractol *fractol, int x, int y);
	t_mouse	*mouse;
}	t_fractol;
