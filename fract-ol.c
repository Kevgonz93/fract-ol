#include "fract-ol.h"

int	main(int argc, char **argv)
{
	t_fractol	*fractol;

	if (argc < 2)
	{
		printf("You can use:");
		printf("\n\tmandelbrot");
		printf("\n\tjulia\n");
		printf("as arguments:\n");
		printf("\tc x y max_iter\n");
		return (1);
	}
	fractol = fractol_init(argv);
	if (!fractol)
		return (1);
	printf("fractol initiated\n");
	printf("fractol->width: %d\n", fractol->width);
	printf("fractol->height: %d\n", fractol->height);
	printf("fractol->zoom: %f\n", fractol->zoom);
	printf("fractol->c: %f\n", fractol->c);
	printf("fractol->x: %f\n", fractol->x);
	printf("fractol->y: %f\n", fractol->y);
	printf("fractol->max_iter: %d\n", fractol->max_iter);
	printf("fractol->current_color->color: %d\n", fractol->current_color->color);
	printf("fractol->fractal: %p\n", fractol->fractal);
	draw_fractol(fractol);
	mlx_loop(fractol->mlx);
	return (0);
}
