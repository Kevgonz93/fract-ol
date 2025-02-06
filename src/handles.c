#include "../fractol-linux.h"

int	zoom_handle(int key, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom;
	double	x_world;
	double	y_world;

	mouse_x = fractol->mouse->x;
	mouse_y = fractol->mouse->y;
	if (key == 43 || key == 65451)
	{
		zoom = 1.1;
		printf("zoom in\n");
	}
	else if (key == 45 || key == 65453)
	{
		zoom = 0.9;
		printf("zoom out\n");
	}
	else
		return (0);
	x_world = (mouse_x - (fractol->width / 2)) / fractol->zoom + fractol->x;
	y_world = (mouse_y - (fractol->height / 2)) / fractol->zoom + fractol->y;
	fractol->zoom *= zoom;
	fractol->x = (x_world - fractol->x) * zoom + fractol->x;
	fractol->y = (y_world - fractol->y) * zoom + fractol->y;
	printf("zoom: %f\n", fractol->zoom);
	draw_fractol(fractol);
	return (0);
}

int	close_handle(t_fractol *fractol)
{
	if (fractol->win)
		mlx_destroy_window(fractol->mlx, fractol->win);
	if (fractol->mlx)
	{
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	if (fractol->mouse)
		free(fractol->mouse);
	free(fractol);
	exit(0);
	return (0);
}

int	move_handle(int key, t_fractol *fractol)
{
	if (key == 123 || key == 65361)
		fractol->x -= 10;
	else if (key == 124 || key == 65363)
		fractol->x += 10;
	else if (key == 126 || key == 65362)
		fractol->y -= 10;
	else if (key == 125 || key == 65364)
		fractol->y += 10;
	printf("x: %f, y: %f\n", fractol->x, fractol->y);
	return (0);
}
