#include "../fract-ol.h"

static void	init_mouse(t_fractol *fractol)
{
	t_mouse	*mouse;

	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!mouse)
	{
		perror("malloc");
		close_handle(fractol);
	}
	fractol->mouse = mouse;
}

static t_colors	*init_colors(void)
{
	t_colors	*colors;

	colors = (t_colors *)malloc(sizeof(t_colors));
	if (!colors)
		return (perror("malloc"), NULL);
	colors->color_1 = (t_color){1, 0x8A2BE2};
	colors->color_2 = (t_color){2, 0xDC143C};
	colors->color_3 = (t_color){3, 0xFF8C00};
	colors->color_4 = (t_color){4, 0x32CD32};
	colors->color_5 = (t_color){5, 0x4682B4};
	colors->color_6 = (t_color){6, 0xDA70D6};
	colors->color_7 = (t_color){7, 0x20B2AA};
	colors->color_8 = (t_color){8, 0xFFD700};
	colors->color_9 = (t_color){9, 0xFF69B4};
	colors->color_10 = (t_color){10, 0x6A5ACD};
	return (colors);
}

static void	init_data(t_fractol *fractol, char **argv)
{
	fractol->colors = init_colors();
	if (!fractol->colors)
	{
		close_handle(fractol);
		return ;
	}
	fractol->width = 800;
	fractol->height = 800;
	fractol->zoom = 1;
	if (argv[5])
		fractol->max_iter = ft_atoi(argv[5]);
	else
		fractol->max_iter = 100;
	if (argv[2])
		fractol->c = get_double(fractol, argv[2]);
	else
		fractol->c = 0;
	if (argv[3])
		fractol->x = get_double(fractol, argv[3]);
	else
		fractol->x = 0;
	if (argv[4])
		fractol->y = get_double(fractol, argv[4]);
	else
		fractol->y = 0;
	fractol->current_color = &fractol->colors->color_1;
}

static void	init_fractal(t_fractol *fractol, char **argv)
{
	if (!strcmp(argv[1], "mandelbrot"))
		fractol->fractal = mandelbrot;
	else if (!strcmp(argv[1], "julia"))
		fractol->fractal = julia;
	else
	{
		perror("invalid fractal");
		close_handle(fractol);
	}
}

t_fractol	*fractol_init(char **fractal)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (perror("malloc"), NULL);
	init_data(fractol, fractal);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (perror("mlx_init fail"), free(fractol), NULL);
	init_fractal(fractol, fractal);
	fractol->win = mlx_new_window(fractol->mlx,
			fractol->width, fractol->height, "fract-ol");
	if (!fractol->win)
	{
		perror("mlx_new_window fail");
		close_handle(fractol);
	}
	init_mouse(fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_loop_hook(fractol->mlx, draw_fractol, fractol);
	mlx_hook(fractol->win, 17, 0, close_handle, fractol);
	return (fractol);
}
