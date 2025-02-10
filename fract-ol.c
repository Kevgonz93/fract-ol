#include "fract-ol.h"

void	mouse_init(t_fractol *fractol)
{
	if (!fractol->mouse)
	{
		perror("malloc");
		close_handle(fractol);
	}
	fractol->mouse->x = 0;
	fractol->mouse->y = 0;
}

t_colors	*init_colors(void)
{
	t_colors	*colors;

	colors = (t_colors *)malloc(sizeof(t_colors));
	if (!colors)
		return (perror("malloc"), NULL);
	colors->color_1 = (t_color){0, 0x000000};
	colors->color_2 = (t_color){1, 0x0000FF};
	colors->color_3 = (t_color){2, 0x00FF00};
	colors->color_4 = (t_color){3, 0x00FFFF};
	colors->color_5 = (t_color){4, 0xFF0000};
	colors->color_6 = (t_color){5, 0xFF00FF};
	colors->color_7 = (t_color){6, 0xFFFF00};
	colors->color_8 = (t_color){7, 0xFFFFFF};
	colors->color_9 = (t_color){8, 0x0F0F0F};
	colors->color_10 = (t_color){9, 0xF0F0F0};
	return (colors);
}

t_fractol	*fractol_init(char *fractal)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (perror("malloc"), NULL);
	fractol->colors = init_colors();
	if (!fractol->colors)
	{
		close_handle(fractol);
		return (NULL);
	}
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (perror("mlx_init fail"), free(fractol), NULL);
	fractol->max_iter = 100;
	fractol->width = 800;
	fractol->height = 800;
	fractol->zoom = 1;
	fractol->x = 0;
	fractol->y = 0;
	fractol->current_color = &fractol->colors->color_1;
	if (!strcmp(fractal, "mandelbrot"))
		fractol->fractal = mandelbrot;
	else if (!strcmp(fractal, "julia"))
		fractol->fractal = julia;
	else
	{
		free(fractol->mlx);
		free(fractol);
		return (perror("invalid fractal"), NULL);
	}
	fractol->win = mlx_new_window(fractol->mlx,
			fractol->width, fractol->height, "fract-ol");
	if (!fractol->win)
	{
		perror("mlx_new_window fail");
		close_handle(fractol);
	}
	fractol->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fractol->mouse)
	{
		perror("malloc");
		close_handle(fractol);
	}
	mouse_init(fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_loop_hook(fractol->mlx, draw_fractol, fractol);
	mlx_hook(fractol->win, 17, 0, close_handle, fractol);
	return (fractol);
}

int	key_hook(int key, t_fractol *fractol)
{
	printf("the key is: %d\n", key);
	if (key == 65307)
		close_handle(fractol);
	else if (key == 43 || key == 65451 || key == 45 || key == 65453)
	{
		mlx_mouse_get_pos(fractol->mlx, fractol->win,
			&fractol->mouse->x, &fractol->mouse->y);
		zoom_handle(key, fractol);
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

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		printf("You can use:");
		printf("\n\t- mandelbrot");
		printf("\n\t- julia\n");
		return (1);
	}
	fractol = fractol_init(argv[1]);
	if (!fractol)
		return (1);
	printf("fractol initiated\n");
	draw_fractol(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
