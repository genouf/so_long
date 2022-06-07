/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:41:49 by genouf            #+#    #+#             */
/*   Updated: 2022/06/07 09:32:22 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

// int	main(int argc, char **argv)
// {
// 	t_game	game;

// 	arg_check(argc, argv[1]);
// 	game = init_map(argv[1], count_lines(argv[1]));
// 	//printf("%p", game.map);
// 	// int i = 0;
// 	// while (i < 8)
// 	// {
// 	// 	printf("%s", game.map[i]);
// 	// 	printf("\n");
// 	// 	i++;
// 	// }
// 	//printf("%c", game.map[0][0]);
// 	check_map(game);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_game		game;
	
	arg_check(argc, argv[1]);
	game = init_map(argv[1], count_lines(argv[1]));
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 60 * game.nb_cols, 60 * game.nb_lines, "Straw Season");
	init_img(game.mlx, &game);
	draw_map(game);
	mlx_loop(game.mlx);
	return (0);	
}