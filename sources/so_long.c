/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:41:49 by genouf            #+#    #+#             */
/*   Updated: 2022/06/08 19:45:14 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

int	main(int argc, char **argv)
{
	t_game		game;
	
	arg_check(argc, argv[1]);
	game = init_map(argv[1], count_lines(argv[1]));
	init_play_struct(&game.play, game);
	check_map(&game);
	game.vars.mlx = mlx_init();
	game.vars.win = mlx_new_window(game.vars.mlx, 60 * game.nb_cols, 60 * game.nb_lines, "Straw Season");
	init_img(game.vars.mlx, &game);
	draw_map(game);
	mlx_hook(game.vars.win, 17, 0L, close_prog, &game.vars);
	mlx_key_hook(game.vars.win, &monitor, &game.vars);
	mlx_loop(game.vars.mlx);
	return (0);	
}