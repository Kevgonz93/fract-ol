#include "../fract-ol.h"

static void	init_mouse(t_fractol *fractol)
{
	t_mouse	*mouse;

	if (!fractol)
	{
		perror("fractol not initialized");
		close_handle(fractol);
		return ;
	}
	mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!mouse)
	{
		perror("malloc");
		close_handle(fractol);
		return ;
	}
	mouse->x = 0;
	mouse->y = 0;
	fractol->mouse = mouse;
}

t_colors	*init_colors(void)
{
	t_colors	*colors;
	int			i;

	colors = malloc(sizeof(t_colors));
	if (!colors)
		return (NULL);
	colors->palette = malloc(sizeof(t_color) * 10);
	if (!colors->palette)
	{
		free(colors);
		return (NULL);
	}
	colors->size = 10;
	i = 0;
	while (i < 10)
	{
		colors->palette[i].index = i;
		colors->palette[i].color = 0xFFFFFF;
		i++;
	}
	reasigning_colors(colors);
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
	fractol->offset_x = 0.0;
	fractol->offset_y = 0.0;
	fractol->zoom = 1.0;
	fractol->escape = 2.0;
	fractol->max_iter = 100;
	fractol->current_color = &fractol->colors->palette[0];
	if (!strcmp(argv[1], "mandelbrot"))
		fractol->fractal = mandelbrot;
	// else if (!strcmp(argv[1], "julia"))
	// 	fractol->fractal = julia;
	else
	{
		perror("invalid fractal");
		close_handle(fractol);
	}
	printf("fractal asignated\n");
}

t_image	init_image(t_fractol *fractol, char **argv)
{
	t_image	image;

	(void)argv;
	image.img = mlx_new_image(fractol->mlx, fractol->width, fractol->height);
	if (!image.img)
	{
		perror("mlx_new_image fail");
		close_handle(fractol);
	}
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel,
			&image.line_length, &image.endian);
	image.width = fractol->width;
	image.height = fractol->height;
	return (image);
}

t_fractol	*fractol_init(char **fractal)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (perror("malloc"), NULL);
	printf("fractol mallocate\n");
	init_data(fractol, fractal);
	printf("data initiated\n");
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
	{
		perror("mlx_init fail");
		close_handle(fractol);
	}
	printf("mlx initiated\n");
	fractol->image = init_image(fractol, fractal);
	if (!fractol->image.img)
	{
		perror("init_image fail");
		close_handle(fractol);
	}
	printf("image initiated\n");
	fractol->win = mlx_new_window(fractol->mlx,
			fractol->width, fractol->height, "fract-ol");
	if (!fractol->win)
	{
		perror("mlx_new_window fail");
		close_handle(fractol);
	}
	printf("window initiated\n");
	init_mouse(fractol);
	if (!fractol->mouse)
	{
		perror("mouse not initiated");
		close_handle(fractol);
	}
	printf("mouse initiated\n");
	printf("------------------- ALL SETTING INITIATED -------------------\n");
	if (!fractol)
	{
		perror("malloc");
		close_handle(fractol);
	}
	printf("mouse : %p\n", fractol->mouse);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_hook(fractol->win, 17, 0, close_handle, fractol);
	return (fractol);
}
