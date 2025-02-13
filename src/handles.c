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
	double	old_zoom;
	double	zoom;

	mlx_mouse_get_pos(fractol->mlx, fractol->win, &fractol->mouse->x, &fractol->mouse->y);
	printf("mouse x: %d mouse y: %d\n", fractol->mouse->x, fractol->mouse->y);
	mouse_x = (fractol->mouse->x - fractol->width / 2.0)
		* (4.0 / fractol->width) * fractol->zoom + fractol->offset_x;
	mouse_y = (fractol->mouse->y - fractol->height / 2.0)
		* (4.0 / fractol->height) * fractol->zoom + fractol->offset_y;
	old_zoom = fractol->zoom;
	if (key == 43 || key == 65451 || key == 4)
		fractol->zoom *= 1.1;
	else if (key == 45 || key == 65453 || key == 5)
		fractol->zoom *= 0.9;
	zoom = fractol->zoom / old_zoom;
	fractol->offset_x = mouse_x - (fractol->mouse->x - fractol->width / 2.0)
        * (4.0 / fractol->width) * fractol->zoom * zoom + fractol->offset_x;
    fractol->offset_y = mouse_y - (fractol->mouse->y - fractol->height / 2.0)
        * (4.0 / fractol->height) * fractol->zoom * zoom + fractol->offset_y;
	printf("zoom: %f\n", fractol->zoom);
	draw_fractol(fractol);
	return (0);
}

int	close_handle(t_fractol *fractol)
{
	if (fractol->image)
	{
		if (fractol->image->img)
			mlx_destroy_image(fractol->mlx, fractol->image->img);
		free(fractol->image);
	}
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
	exit(1);
}

// int	move_handle(int key, t_fractol *fractol)
// {

// }

void	reset_fractol(t_fractol *fractol)
{
	fractol->width = 800;
	fractol->height = 800;
	fractol->zoom = 1;
	fractol->max_iter = 100;
	fractol->current_color = &fractol->colors->color_1;
	fractol->image->width = fractol->width;
	fractol->image->height = fractol->height;
	draw_fractol(fractol);
}
