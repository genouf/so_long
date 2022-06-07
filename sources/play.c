/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:27:21 by genouf            #+#    #+#             */
/*   Updated: 2022/06/07 12:09:46 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	move(int direction, t_play_g *play, t_game *game)
{
	t_coord next_position;

	if (direction == 1)
	{
		
	}
	else if (direction == 2)

	else if (direction == 3)

	else if (direction == 4)
}

void	monitor(int keycode, t_vars *vars, t_game game)
{
	if (keycode == 65307)
		close_prog(game);
	else if (keycode == 119)
		
	else if (keycode == 97)

	else if (keycode == 115)

	else if (keycode == 100)
}