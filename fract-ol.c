#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		printf("You can use:");
		printf("\n\tmandelbrot");
		printf("\n\tjulia\n");
		return (1);
	}
	fractol = fractol_init(argv);
	if (!fractol)
		return (1);
	printf("fractol initiated\n");
	draw_fractol(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
