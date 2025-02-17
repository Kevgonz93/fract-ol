#include "../fract-ol.h"

void	next_color(t_fractol *fractol)
{
	if (fractol->current_color->index == fractol->colors->size - 1)
		fractol->current_color = &fractol->colors->palette[0];
	else
		fractol->current_color++;
}

void	color_handle(int key, t_fractol *fractol)
{
	if (!fractol || !fractol->colors)
	{
		perror("fractol/colors not initialized");
		close_handle(fractol);
	}
	if (key == 49)
		fractol->current_color = &fractol->colors->palette[0];
	else if (key == 50)
		fractol->current_color = &fractol->colors->palette[1];
	else if (key == 51)
		fractol->current_color = &fractol->colors->palette[2];
	else if (key == 52)
		fractol->current_color = &fractol->colors->palette[3];
	else if (key == 53)
		fractol->current_color = &fractol->colors->palette[4];
	else if (key == 54)
		fractol->current_color = &fractol->colors->palette[5];
	else if (key == 55)
		fractol->current_color = &fractol->colors->palette[6];
	else if (key == 56)
		fractol->current_color = &fractol->colors->palette[7];
	else if (key == 57)
		fractol->current_color = &fractol->colors->palette[8];
	else if (key == 48)
		fractol->current_color = &fractol->colors->palette[9];
	else if (key == 1)
		next_color(fractol);
	printf("color: %d\n", fractol->current_color->color);
	draw_fractol(fractol);
}

int	zoom_handle(int key, t_fractol *fractol)
{
	double	mouse_x;
	double	mouse_y;
	double	zoom_factor;

	if (!fractol || !fractol->mouse)
	{
		perror("fractol/mouse not initialized");
		close_handle(fractol);
	}
	mouse_x = fractol->offset_x + (fractol->mouse->x - fractol->width / 2.0)
		* (4.0 / fractol->width) * fractol->zoom;
	mouse_y = fractol->offset_y + (fractol->mouse->y - fractol->height / 2.0)
		* (4.0 / fractol->height) * fractol->zoom;
	mlx_mouse_get_pos(fractol->mlx, fractol->win, &fractol->mouse->x, &fractol->mouse->y);
	printf("mouse x: %d mouse y: %d\n", fractol->mouse->x, fractol->mouse->y);
	if (key == 43 || key == 65451 || key == 4)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	fractol->zoom *= zoom_factor;
	fractol->offset_x = mouse_x - ((mouse_x - fractol->offset_x) / zoom_factor);
	fractol->offset_y = mouse_y - ((mouse_y - fractol->offset_y) / zoom_factor);
	printf("zoom: %f\n", fractol->zoom);
	draw_fractol(fractol);
	return (0);
}

int	move_handle(int key, t_fractol *fractol)
{
	if (key == 123 || key == 65361)
		fractol->offset_x -= 0.1 / fractol->zoom;
	else if (key == 124 || key == 65363)
		fractol->offset_x += 0.1 / fractol->zoom;
	else if (key == 126 || key == 65362)
		fractol->offset_y -= 0.1 / fractol->zoom;
	else if (key == 125 || key == 65364)
		fractol->offset_y += 0.1 / fractol->zoom;
	printf("offset x: %f offset y: %f\n", fractol->offset_x, fractol->offset_y);
	draw_fractol(fractol);
	return (0);
}

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

int	close_handle(t_fractol *fractol)
{
	if (!fractol)
	{
		perror("fractol not initialized");
		exit(1);
	}
	if (fractol->image.img)
		mlx_destroy_image(fractol->mlx, fractol->image.img);
	if (fractol->mlx)
	{
		if (fractol->win)
			mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
		free(fractol->mlx);
	}
	if (fractol->mouse)
		free(fractol->mouse);
	if (fractol->colors)
		free(fractol->colors);
	if (fractol)
		free(fractol);
	printf("fract-ol closed\n");
	exit(0);
}
