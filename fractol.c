#include "fractol.h"

t_fractol	*fractol_init(char **fractal)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (perror("malloc"), NULL);
	init_data(fractol, fractal);
	fractol->mlx = mlx_init();
	fractol->image = init_image(fractol, fractal);
	fractol->win = mlx_new_window(fractol->mlx,
			fractol->width, fractol->height, "fract-ol");
	init_mouse(fractol);
	if (!fractol->mouse || !fractol->mlx
		|| !fractol->win || !fractol->image.img)
	{
		perror("fractol not initialized");
		close_handle(fractol);
	}
	ft_printf("-------------------------");
	ft_printf(" ALL SETTINGS INITIALIZED ");
	ft_printf("-------------------------\n");
	return (fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		ft_printf("usage: %s [fractal]\n", argv[0]);
		ft_printf("\tmandelbrot\n");
		ft_printf("\tjulia [c_real] [c_imaginary]\n");
		ft_printf("\ttricorn\n");
		return (0);
	}
	fractol = fractol_init(argv);
	if (!fractol)
		return (0);
	mlx_mouse_hook(fractol->win, mouse_hook, fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
	mlx_hook(fractol->win, 17, 0, close_handle, fractol);
	draw_fractol(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
