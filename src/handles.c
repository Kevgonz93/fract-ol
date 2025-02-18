#include "../fractol.h"

void	color_handle(int key, t_fractol *fractol)
{
	if (!fractol || !fractol->colors)
	{
		perror("fractol/colors not initialized");
		close_handle(fractol);
	}
	if (key > 47 && key < 58)
	{
		printf("key: %d\n", key);
		fractol->current_color = &fractol->colors->palette[key - 48];
	}
	else if (key == 1)
		next_color(fractol);
	printf("color: %d\n", fractol->current_color->color);
	draw_fractol(fractol);
}
// FUNCTION FOR GETTING THE MOUSE POSITION
static double	aux_zoom_handle(t_fractol *fratol, char c)
{
	if (c == 'x')
		return (fratol->offset_x + (fratol->mouse->x - fratol->width / 2.0)
			* (4.0 / fratol->width) * fratol->zoom);
	else if (c == 'y')
		return (fratol->offset_y + (fratol->mouse->y - fratol->height / 2.0)
			* (4.0 / fratol->height) * fratol->zoom);
	return (0);
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
	mouse_x = aux_zoom_handle(fractol, 'x');
	mouse_y = aux_zoom_handle(fractol, 'y');
	mlx_mouse_get_pos(fractol->mlx, fractol->win,
		&fractol->mouse->x, &fractol->mouse->y);
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
	if (fractol->colors->palette)
		free(fractol->colors->palette);
	if (fractol->colors)
		free(fractol->colors);
	if (fractol)
		free(fractol);
	printf("fract-ol closed\n");
	exit(0);
}
