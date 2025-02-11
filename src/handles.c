#include "../fract-ol.h"

void	color_handle(int key, t_fractol *fractol)
{
	if (key == 49)
		fractol->current_color = &fractol->colors->color_1;
	else if (key == 50)
		fractol->current_color = &fractol->colors->color_2;
	else if (key == 51)
		fractol->current_color = &fractol->colors->color_3;
	else if (key == 52)
		fractol->current_color = &fractol->colors->color_4;
	else if (key == 53)
		fractol->current_color = &fractol->colors->color_5;
	else if (key == 54)
		fractol->current_color = &fractol->colors->color_6;
	else if (key == 55)
		fractol->current_color = &fractol->colors->color_7;
	else if (key == 56)
		fractol->current_color = &fractol->colors->color_8;
	else if (key == 57)
		fractol->current_color = &fractol->colors->color_9;
	else if (key == 48)
		fractol->current_color = &fractol->colors->color_10;
	printf("color: %d\n", fractol->current_color->index);
	draw_fractol(fractol);
}

int	zoom_handle(int key, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom;
	double	x_world;
	double	y_world;

	zoom = fractol->zoom;
	mouse_x = fractol->mouse->x;
	mouse_y = fractol->mouse->y;
	if (key == 43 || key == 65451)
		zoom *= 1.1;
	else
		zoom *= 0.9;
	if (zoom < 0.0001)
		zoom = 0.0001;
	x_world = fractol->x + (mouse_x - fractol->width / 2)
		* (4.0 / fractol->zoom) / fractol->width;
	y_world = fractol->y + (mouse_y - fractol->height / 2)
		* (4.0 / fractol->zoom) / fractol->height;
	fractol->zoom = zoom;
	fractol->x = x_world - (mouse_x - fractol->width / 2)
		* (4.0 / fractol->zoom) / fractol->width;
	fractol->y = y_world - (mouse_y - fractol->height / 2)
		* (4.0 / fractol->zoom) / fractol->height;
	printf("zoom: %f\n", fractol->zoom);
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
	if (fractol->colors)
		free(fractol->colors);
	free(fractol);
	printf("fract-ol closed\n");
	exit(0);
	return (0);
}

int	move_handle(int key, t_fractol *fractol)
{
	double	move;

	move = (1.0 / fractol->zoom) * 0.3;
	if (key == 123 || key == 65361)
		fractol->x -= move;
	else if (key == 124 || key == 65363)
		fractol->x += move;
	else if (key == 126 || key == 65362)
		fractol->y -= move;
	else if (key == 125 || key == 65364)
		fractol->y += move;
	printf("x: %f, y: %f\n", fractol->x, fractol->y);
	return (0);
}

void	reset_fractol(t_fractol *fractol)
{
	fractol->zoom = 1;
	fractol->x = 0;
	fractol->y = 0;
	fractol->max_iter = 100;
	fractol->current_color = &fractol->colors->color_1;
	printf("fract-ol reset\n");
}
