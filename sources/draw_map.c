/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:42:09 by genouf            #+#    #+#             */
/*   Updated: 2022/06/06 19:40:26 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	draw_bg(void* mlx, void *mlx_win, t_game game)
{
	t_data	bg;
	int		i;
	int		j;
	int		color;
	
	color = rgb_to_int(0, 235, 213, 173);
	bg.img = mlx_new_image(mlx, 60 * game.nb_cols, 60 * game.nb_lines);
	bg.addr = mlx_get_data_addr(bg.img, &bg.bits_per_pixel,&bg.line_length,
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
	mlx_put_image_to_window(mlx, mlx_win, bg.img, 0, 0);
}