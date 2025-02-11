#include "../fract-ol.h"

int	key_hook(int key, t_fractol *fractol)
{
	printf("the key is: %d\n", key);
	if (key == 65307)
		close_handle(fractol);
	else if (key == 43 || key == 65451 || key == 45 || key == 65453)
	{
		mlx_mouse_get_pos(fractol->mlx, fractol->win,
			&fractol->mouse->x, &fractol->mouse->y);
		zoom_handle(key, fractol);
		draw_fractol(fractol);
	}
	else if (key == 123 || key == 65361 || key == 124 || key == 65363
		|| key == 126 || key == 65362 || key == 125 || key == 65364)
		move_handle(key, fractol);
	else if (key >= 48 && key <= 57)
	{
		color_handle(key, fractol);
		draw_fractol(fractol);
	}
	else if (key == 32)
	{
		reset_fractol(fractol);
		draw_fractol(fractol);
	}
	return (0);
}

int	draw_fractol(t_fractol *fractol)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < fractol->height)
	{
		x = 0;
		while (x < fractol->width)
		{
			color = fractol->fractal(fractol, x, y);
			mlx_pixel_put(fractol->mlx, fractol->win, x, y, color);
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	return (result * sign);
}

float	ft_atof(const char *str)
{
	float	result;
	float	sign;
	float	decimal;
	int		i;

	result = 0;
	sign = 1;
	decimal = 0;
	i = 0;
	if (str[i++] == '-')
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - '0';
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i++] - '0';
			decimal++;
		}
	}
	while (decimal--)
		result /= 10;
	printf("result: %f\n", result);
	return (result * sign);
}

double	get_double(t_fractol *fractol, char *argv)
{
	double	new_value;

	new_value = ft_atof(argv);
	if (new_value < -2.0 || new_value > 2.0)
	{
		perror("Invalid value for Julia");
		close_handle(fractol);
	}
	return (new_value);
}
