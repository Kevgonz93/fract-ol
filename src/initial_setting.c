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
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
}

static t_colors	*init_colors(void)
{
	t_colors	*colors;

	colors = (t_colors *)malloc(sizeof(t_colors));
	if (!colors)
	{
		perror("malloc");
		free(colors);
		return (NULL);
	}
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
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->zoom = 1;
	fractol->max_iter = 100;
	fractol->current_color = &fractol->colors->color_1;
	if (!strcmp(argv[1], "mandelbrot"))
	{
		fractol->fractal = mandelbrot;
		printf("generating mandelbrot\n");
	}
	// else if (!strcmp(argv[1], "julia"))
	// 	fractol->fractal = julia;
	else
	{
		perror("invalid fractal");
		close_handle(fractol);
	}
}

static void	init_image(t_fractol *fractol, char **argv)
{
	t_image	*image;
	(void)argv;

	image = (t_image *)malloc(sizeof(t_image));
	if (!image)
	{
		perror("malloc");
		close_handle(fractol);
	}
	image->img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	if (!image->img)
	{
		perror("mlx_new_image fail");
		free(image);
		close_handle(fractol);
	}
	image->addr = mlx_get_data_addr(image->img,
			&image->bits_per_pixel, &image->line_length, &image->endian);
	if (!image->addr)
	{
		perror("mlx_get_data_addr fail");
		free(image);
		close_handle(fractol);
	}
	image->width = fractol->width;
	image->height = fractol->height;
	fractol->image = image;
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
	init_image(fractol, fractal);
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
