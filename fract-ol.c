#include "fractol-mac.h"
#include "fractol-linux.h"

void	mouse_init(t_fractol *fractol)
{
	fractol->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fractol->mouse)
	{
		perror("malloc");
		free(fractol->mlx);
		free(fractol->mouse);
		free(fractol);
		exit(1);
	}
	fractol->mouse->x = 0;
	fractol->mouse->y = 0;
	mlx_mouse_hook(fractol->win, mouse_click, fractol);
	mlx_hook(fractol->win, 6, 0, mouse_move, fractol);
	mlx_key_hook(fractol->win, key_hook, fractol);
}

t_fractol	*fractol_init(int width, int height)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fractol)
		return (perror("malloc"), NULL);
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (perror("mlx_init fail"), free(fractol), NULL);
	fractol->width = width;
	fractol->height = height;
	fractol->zoom = 1;
	fractol->x = 0;
	fractol->y = 0;
	fractol->win = mlx_new_window(fractol->mlx,
			fractol->width, fractol->height, "fract-ol");
	if (!fractol->win)
	{
		perror("mlx_new_window fail");
		free(fractol->mlx);
		free(fractol);
		return (NULL);
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
	if (key == 53 || key == 65307)
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
	return (0);
}

int	main(int argc, char **argv)
{
	t_fractol	*fractol;
	int			width;
	int			height;

	if (argc < 3)
	{
		printf("You can use:");
		printf("\n\t- mandelbrot");
		printf("\n\t- julia\n");
		return (1);
	}
	width = atoi(argv[1]);
	height = atoi(argv[2]);
	fractol = fractol_init(width, height);
	if (!fractol)
		return (1);
	mlx_loop(fractol->mlx);
	return (0);
}
