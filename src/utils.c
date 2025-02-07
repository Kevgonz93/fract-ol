#include "../fract-ol.h"

int	mouse_move(int x, int y, t_fractol *fractol)
{
	fractol->mouse->x = x;
	fractol->mouse->y = y;
	return (0);
}

int	mandelbrot(t_fractol *fractol, int px, int py)
{
	double	x;
	double	y;
	double	x2;
	double	y2;
	double	x_temp;
	int		i;
	double	zoom;

	zoom = fractol->zoom;
	x = (px - (fractol->width / 2.0)) * (4.0 / zoom) / fractol->width + fractol->x;
	y = (py - (fractol->height / 2.0)) * (4.0 / zoom) / fractol->height + fractol->y;
	x2 = 0;
	y2 = 0;
	i = 0;
	while (x2 * x2 + y2 * y2 <= 4 && i < fractol->max_iter)
	{
		x_temp = x2 * x2 - y2 * y2 + x;
		y2 = 2 * x2 * y2 + y;
		x2 = x_temp;
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000);
	return (fractol->color * i);
}

int	draw_fractol(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < fractol->height)
	{
		x = 0;
		while (x < fractol->width)
		{
			color = fractol->fractal(fractol, x, y);
			mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}
