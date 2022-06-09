/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:30:41 by genouf            #+#    #+#             */
/*   Updated: 2022/06/09 12:57:32 by genouf           ###   ########.fr       */
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
	game->block.image = mlx_xpm_file_to_image(mlx, "./images/block.xpm",
			&(game->straw_bale.width), &(game->straw_bale.height));
}

int	close_prog(t_game *game)
{
	free_init_map(game->map, game->nb_lines - 1, NULL);
	mlx_destroy_image(game->vars.mlx, game->road.image);
	mlx_destroy_image(game->vars.mlx, game->telesco.image);
	mlx_destroy_image(game->vars.mlx, game->straw_bale.image);
	mlx_destroy_image(game->vars.mlx, game->tree.image);
	mlx_destroy_image(game->vars.mlx, game->block.image);
	mlx_destroy_window(game->vars.mlx, game->vars.win);
	mlx_destroy_display(game->vars.mlx);
	free(game->vars.mlx);
	exit(0);
}

void	init_play_struct(t_play_g *play, t_game game)
{
	int	j;
	int	i;

	play->pre_value = '0';
	play->step_counter = 0;
	play->items_col = 0;
	i = 1;
	while (i < game.nb_lines - 1)
	{
		j = 1;
		while (j < game.nb_cols - 1)
		{
			if (game.map[i][j] == 'P')
			{
				play->pos_p.x = j;
				play->pos_p.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
