#include "../fractol.h"

int	aux_tricorn(t_fractol *fractol, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < fractol->max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = -2 * z_re * z_im + c_im;
		z_re = tmp;
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000);
	return (fractol->current_color->color * i / fractol->max_iter);
}

int	tricorn(t_fractol *fractol, int x, int y)
{
	double	c_re;
	double	c_im;

	c_re = fractol->offset_x + (x - fractol->width / 2.0)
		* (4.0 / fractol->width) / fractol->zoom;
	c_im = fractol->offset_y + (y - fractol->height / 2.0)
		* (4.0 / fractol->height) / fractol->zoom;
	return (aux_tricorn(fractol, c_re, c_im));
}

int	aux_mandelbrot(t_fractol *fractol, double c_re, double c_im)
{
	int		i;
	double	z_re;
	double	z_im;
	double	tmp;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < fractol->max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + c_re;
		z_im = 2 * z_re * z_im + c_im;
		z_re = tmp;
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000);
	return (fractol->current_color->color * i / fractol->max_iter);
}

int	mandelbrot(t_fractol *fractol, int x, int y)
{
	double	c_re;
	double	c_im;

	c_re = fractol->offset_x + (x - fractol->width / 2.0)
		* (4.0 / fractol->width) / fractol->zoom;
	c_im = fractol->offset_y + (y - fractol->height / 2.0)
		* (4.0 / fractol->height) / fractol->zoom;
	return (aux_mandelbrot(fractol, c_re, c_im));
}

int	julia(t_fractol *fractol, int px, int py)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	z_re = fractol->offset_x + (px - fractol->width / 2.0)
		* (4.0 / fractol->width) / fractol->zoom;
	z_im = fractol->offset_y + (py - fractol->height / 2.0)
		* (4.0 / fractol->height) / fractol->zoom;
	i = 0;
	while (z_re * z_re + z_im * z_im <= 4 && i < fractol->max_iter)
	{
		tmp = z_re * z_re - z_im * z_im + fractol->c_re;
		z_im = 2 * z_re * z_im + fractol->c_im;
		z_re = tmp;
		i++;
	}
	if (i == fractol->max_iter)
		return (0x000000);
	return (fractol->current_color->color * i / fractol->max_iter);
}
