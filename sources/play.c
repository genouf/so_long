/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:27:21 by genouf            #+#    #+#             */
/*   Updated: 2022/06/09 12:59:05 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

void	init_direction(int direction, t_game game, t_coord *next_position)
{
	if (direction == 1)
	{
		next_position->x = game.play.pos_p.x;
		next_position->y = game.play.pos_p.y - 1;
	}
	else if (direction == 2)
	{
		next_position->x = game.play.pos_p.x - 1;
		next_position->y = game.play.pos_p.y;
	}
	else if (direction == 3)
	{
		next_position->x = game.play.pos_p.x;
		next_position->y = game.play.pos_p.y + 1;
	}
	else if (direction == 4)
	{
		next_position->x = game.play.pos_p.x + 1;
		next_position->y = game.play.pos_p.y;
	}
}

void	switch_position(t_game *game, t_coord next_position)
{
	if (game->map[next_position.y][next_position.x] == 'C')
		game->play.items_col++;
	game->map[next_position.y][next_position.x] = 'P';
	game->map[game->play.pos_p.y][game->play.pos_p.x] = game->play.pre_value;
	game->play.pre_value = '0';
	game->play.pos_p.x = next_position.x;
	game->play.pos_p.y = next_position.y;
	game->play.step_counter++;
	ft_printf("Number of steps : %d\n", game->play.step_counter);
}

void	move(int direction, t_game *game)
{
	t_coord		next_position;

	init_direction(direction, *game, &next_position);
	if (game->map[next_position.y][next_position.x] == 'E' &&
			game->play.items_total == game->play.items_col)
		close_prog(game);
	else if (game->map[next_position.y][next_position.x] == 'C' ||
			game->map[next_position.y][next_position.x] == '0')
		switch_position(game, next_position);
	render_map(*game);
}

int	monitor(int keycode, t_game *game)
{
	if (keycode == 65307)
		close_prog(game);
	else if (keycode == 119)
		move(1, game);
	else if (keycode == 97)
		move(2, game);
	else if (keycode == 115)
		move(3, game);
	else if (keycode == 100)
		move(4, game);
	return (0);
}
