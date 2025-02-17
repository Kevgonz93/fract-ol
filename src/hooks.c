#include "../fract-ol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (!fractol || !fractol->mouse)
	{
		perror("fractol/mouse not initialized");
		close_handle(fractol);
	}
	printf("the key is: %d\n", button);
	if (button == 4 || button == 5)
	{
		zoom_handle(button, fractol);
		return (1);
	}
	else if (button == 1)
	{
		color_handle(button, fractol);
		return (1);
	}
	return (0);
}

int	key_hook(int key, t_fractol *fractol)
{
	printf("the key is: %d\n", key);
	if (key == 65307)
		close_handle(fractol);
	else if (key == 43 || key == 65451
		|| key == 45 || key == 65453)
	{
		zoom_handle(key, fractol);
		draw_fractol(fractol);
	}
	else if (key == 123 || key == 65361 || key == 124 || key == 65363
		|| key == 126 || key == 65362 || key == 125 || key == 65364)
		move_handle(key, fractol);
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
