/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:42:09 by genouf            #+#    #+#             */
/*   Updated: 2022/06/07 09:40:27 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	draw_bg(t_game game)
{
	t_data	bg;
	int		i;
	int		j;
	int		color;

	color = rgb_to_int(0, 235, 213, 173);
	bg.img = mlx_new_image(game.mlx, 60 * game.nb_cols, 60 * game.nb_lines);
	bg.addr = mlx_get_data_addr(bg.img, &bg.bits_per_pixel, &bg.line_length,
			&bg.endian);
	i = 0;
	while (i < 60 * game.nb_lines + 1)
	{
		j = 0;
		while (j < 60 * game.nb_cols + 1)
		{
			mlx_draw_pixel(&bg, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game.mlx, game.mlx_win, bg.img, 0, 0);
}

void	draw_image(char c, t_game game, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game.mlx, game.mlx_win, game.tree.image, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game.mlx, game.mlx_win, game.road.image, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.telesco.image, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game.mlx, game.mlx_win,
			game.straw_bale.image, x, y);
}

void	render_map(t_game game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game.nb_lines)
	{
		j = 0;
		while (j < game.nb_cols)
		{
			draw_image(game.map[i][j], game, j * 60, i * 60);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game game)
{
	draw_bg(game);
	render_map(game);
}
