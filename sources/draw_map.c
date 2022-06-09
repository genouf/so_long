/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:42:09 by genouf            #+#    #+#             */
/*   Updated: 2022/06/09 12:55:31 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	draw_image(char c, t_game game, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(game.vars.mlx, game.vars.win,
			game.tree.image, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game.vars.mlx, game.vars.win,
			game.road.image, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game.vars.mlx, game.vars.win,
			game.telesco.image, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game.vars.mlx, game.vars.win,
			game.straw_bale.image, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game.vars.mlx, game.vars.win,
			game.block.image, x, y);
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
