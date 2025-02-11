#include "../fract-ol.h"
#include <errno.h>

static int	check_fractal(t_fractol *fractol, double x, double y)
{
	double	x2;
	double	y2;
	double	x_temp;	
	int		i;

	x2 = fractol->x;
	y2 = fractol->y;
	i = 0;
	while (x2 * x2 + y2 * y2 <= 4 && i < fractol->max_iter)
	{
		x_temp = x2 * x2 - y2 * y2 + x;
		y2 = 2 * x2 * y2 + y;
		x2 = x_temp;
		i++;
	}
	return (i);
}

int	mandelbrot(t_fractol *fractol, int px, int py)
{
	double	x;
	double	y;
	double	zoom;
	int		i;

	zoom = fractol->zoom;
	x = (px - (fractol->width / 2.0))
		* (4.0 / zoom) / fractol->width + fractol->x;
	y = (py - (fractol->height / 2.0))
		* (4.0 / zoom) / fractol->height + fractol->y;
	i = check_fractal(fractol, x, y);
	if (i == 0)
		return (0x000000);
	return (fractol->current_color->color * i);
}

int	julia(t_fractol *fractol, int px, int py)
{
	double	x;
	double	y;
	int		i;

	x = (px - (fractol->width / 2.0))
		* (4.0 / fractol->zoom) / fractol->width + fractol->x;
	y = (py - (fractol->height / 2.0))
		* (4.0 / fractol->zoom) / fractol->height + fractol->y;
	i = check_fractal(fractol, x, y);
	if (i == 0)
		return (0x000000);
	return (fractol->current_color->color * i);
}

