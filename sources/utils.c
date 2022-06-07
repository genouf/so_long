/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:30:41 by genouf            #+#    #+#             */
/*   Updated: 2022/06/07 09:30:59 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

int	rgb_to_int(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	mlx_draw_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_img(void *mlx, t_game *game)
{
	game->telesco.image = mlx_xpm_file_to_image(mlx, "./images/telesco.xpm",
			&(game->telesco.width), &(game->telesco.height));
	game->tree.image = mlx_xpm_file_to_image(mlx, "./images/tree.xpm",
			&(game->tree.width), &(game->tree.height));
	game->road.image = mlx_xpm_file_to_image(mlx, "./images/road.xpm",
			&(game->road.width), &(game->road.height));
	game->straw_bale.image = mlx_xpm_file_to_image(mlx,
			"./images/straw_bale.xpm",
			&(game->straw_bale.width), &(game->straw_bale.height));
}
