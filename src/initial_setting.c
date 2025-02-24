#include "../fractol.h"

void	init_mouse(t_fractol *fractol)
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
	ft_printf("mouse initiated\n");
}

static t_colors	*init_colors(void)
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
	ft_printf("colors initiated\n");
	return (colors);
}

static void	init_fractal(t_fractol *fractol, char **argv)
{
	if (!ft_strncmp(argv[1], "mandelbrot", 10))
		fractol->fractal = mandelbrot;
	else if (!ft_strncmp(argv[1], "julia", 5))
	{
		if (argv[2] && argv[3])
		{
			fractol->c_re = ft_atof(argv[2]);
			fractol->c_im = ft_atof(argv[3]);
		}
		else
		{
			fractol->c_re = -0.7;
			fractol->c_im = 0.27015;
		}
		fractol->fractal = julia;
	}
	else if (!ft_strncmp(argv[1], "tricorn", 7))
		fractol->fractal = tricorn;
	else
	{
		perror("invalid fractal");
		close_handle(fractol);
	}
	ft_printf("fractal initiated\n");
}

void	init_data(t_fractol *fractol, char **argv)
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
	init_fractal(fractol, argv);
	ft_printf("data initiated\n");
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
	ft_printf("image initiated\n");
	return (image);
}
