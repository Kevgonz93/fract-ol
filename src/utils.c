#include "../fract-ol.h"

int	mouse_hook(int key, t_fractol *fractol)
{
	printf("the key is: %d\n", key);
	if (!fractol->mouse)
	{
		perror("mouse not initialized");
		close_handle(fractol);
	}
	else if (key == 4 || key == 5)
	{
		mlx_mouse_get_pos(fractol->mlx, fractol->win,
			&fractol->mouse->x, &fractol->mouse->y);
		zoom_handle(key, fractol);
		draw_fractol(fractol);
	}
	return (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	printf("the key is: %d\n", key);
	if (key == 65307)
		close_handle(fractol);
	else if (key == 43 || key == 65451 || key == 4
		|| key == 45 || key == 65453 || key == 5)
	{
		mlx_mouse_get_pos(fractol->mlx, fractol->win,
			&fractol->mouse->x, &fractol->mouse->y);
		zoom_handle(key, fractol);
		draw_fractol(fractol);
	}
	// else if (key == 123 || key == 65361 || key == 124 || key == 65363
	// 	|| key == 126 || key == 65362 || key == 125 || key == 65364)
	// 	move_handle(key, fractol);
	else if (key >= 48 && key <= 57)
	{
		color_handle(key, fractol);
		draw_fractol(fractol);
	}
	else if (key == 32)
	{
		reset_fractol(fractol);
		draw_fractol(fractol);
	}
	return (0);
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
			put_pixel(fractol->image, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win,
		fractol->image->img, 0, 0);
	mlx_do_sync(fractol->mlx);
	return (0);
}

