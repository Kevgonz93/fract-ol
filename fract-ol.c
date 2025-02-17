#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		printf("You can use:");
		printf("\n\tmandelbrot");
		printf("\n\tjulia c_re c_im\n");
		return (0);
	}
	fractol = fractol_init(argv);
	if (!fractol)
		return (0);
	draw_fractol(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
