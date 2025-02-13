#include "../fract-ol.h"

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_image;

typedef struct s_color
{
	int	index;
	int	color;
}	t_color;

typedef struct s_colors
{
	t_color	color_1;
	t_color	color_2;
	t_color	color_3;
	t_color	color_4;
	t_color	color_5;
	t_color	color_6;
	t_color	color_7;
	t_color	color_8;
	t_color	color_9;
	t_color	color_10;
}	t_colors;

typedef struct s_mouse
{
	int		x;
	int		y;
}	t_mouse;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	double		offset_x;
	double		offset_y;
	double		zoom;
	int			max_iter;
	t_image		*image;
	t_colors	*colors;
	t_color		*current_color;
	t_mouse		*mouse;
	int			(*fractal)(struct s_fractol *fractol, int x, int y);
}	t_fractol;
