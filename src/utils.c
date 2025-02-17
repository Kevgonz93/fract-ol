#include "../fract-ol.h"

void	reasigning_colors(t_colors *colors)
{
	colors->palette[0].color = 0x8A2BE2;
	colors->palette[1].color = 0xDC143C;
	colors->palette[2].color = 0xFF8C00;
	colors->palette[3].color = 0x32CD32;
	colors->palette[4].color = 0x4682B4;
	colors->palette[5].color = 0xDA70D6;
	colors->palette[6].color = 0x20B2AA;
	colors->palette[7].color = 0xFFD700;
	colors->palette[8].color = 0xFF69B4;
	colors->palette[9].color = 0x6A5ACD;
}

void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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
			put_pixel(&fractol->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->image.img, 0, 0);
	return (0);
}

