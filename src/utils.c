#include "../fractol.h"

// FUNCTION FOR CHANGE FOR THE NEXT COLOR
void	next_color(t_fractol *fractol)
{
	if (fractol->current_color->index == fractol->colors->size - 1)
		fractol->current_color = &fractol->colors->palette[0];
	else
		fractol->current_color++;
}

// FUNCTION FOR REASIGNING COLORS - COLORS OF THE PALETTE
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

// FUNCTION FOR DRAWING PIXELS
void	put_pixel(t_image *image, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= image->width || y >= image->height)
		return ;
	dst = image->addr + (y * image->line_length + x
			* (image->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// FUNCTION FOR DRAWING FRACTOL
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

// FUNCTION FOR RESETING FRACTOL
void	reset_fractol(t_fractol *fractol)
{
	fractol->width = 800;
	fractol->height = 800;
	fractol->zoom = 1;
	fractol->max_iter = 100;
	fractol->current_color = &fractol->colors->palette[0];
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	draw_fractol(fractol);
}
