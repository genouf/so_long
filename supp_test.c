#include <stdio.h>
#include "includes/so_long.h"

#define SIZE		22

void	draw_a_square(t_data *img, int color)
{
	int	i;

	i = 59;
	while (++i < 460)
	{
		mlx_draw_pixel(img, i, 60, color);
		mlx_draw_pixel(img, i, 460, color);
	}
	i = 59;
	while (++i < 460)
	{
		mlx_draw_pixel(img, 60, i, color);
		mlx_draw_pixel(img, 460, i, color);
	}
}

void	print_rainbow_color(t_data *img, int x, int y)
{
	int	count;
	
	count = -1;
	while (++count < SIZE)
	{
		mlx_draw_pixel(img, x, y, rgb_to_int(0, 232, 14, 27));
		y++;
	}
	count = -1;
	while (++count < SIZE)
	{
		mlx_draw_pixel(img, x, y, rgb_to_int(0, 224, 102, 19));
		y++;
	}
	count = -1;
	while (++count < SIZE)
	{
		mlx_draw_pixel(img, x, y, rgb_to_int(0, 247, 217, 37));
		y++;
	}
	count = -1;
	while (++count < SIZE)
	{
		mlx_draw_pixel(img, x, y, rgb_to_int(0, 19, 152, 73));
		y++;
	}
	count = -1;
	while (++count < SIZE)
	{
		mlx_draw_pixel(img, x, y, rgb_to_int(0, 27, 62, 145));
		y++;
	}
	count = -1;
	while (++count < SIZE)
	{
		mlx_draw_pixel(img, x, y, rgb_to_int(0, 120, 64, 146));
		y++;
	}
}

void	draw_a_raimbow(t_data *img)
{
	int	x;
	int	y;

	x = 20;
	y = 320;
	while (y > 121)
	{
		print_rainbow_color(&img, x, y);
		y--;
		x++;
	}
	while (y < 321)
	{
		print_rainbow_color(&img, x, y);
		y++;
		x++;
	}
}

int	main(void)
{
	printf("%d", 2 << 2);
	return (0);
}