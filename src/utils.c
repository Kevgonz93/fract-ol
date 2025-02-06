#include "../fractol-linux.h"

int	mouse_click(int button, int x, int y, t_fractol *fractol)
{
	if (button == 1)
	{
		printf("mouse click at x: %d, y: %d\n", x, y);
		mlx_pixel_put(fractol->mlx, fractol->win, x, y, 0xFFFFFF);
	}
	return (0);
}

int	mouse_move(int x, int y, t_fractol *fractol)
{
	fractol->mouse->x = x;
	fractol->mouse->y = y;
	return (0);
}

int	draw_fractol(t_fractol *fractol)
{
	(void)fractol;
	// mlx_clear_window(fractol->mlx, fractol->win);
	return (0);
}
