/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:41:49 by genouf            #+#    #+#             */
/*   Updated: 2022/06/07 11:27:08 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

/*int	main(int argc, char **argv)
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
}*/

// int close_prog(int keycode, t_vars *vars)
// {
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		exit(EXIT_SUCCESS);
// 	}
// }

int	main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 720, 480, "test");
	mlx_key_hook(vars.win, close_prog, &vars);
	mlx_hook(vars.win, 17, 0L, close_prog, &vars);
	mlx_loop(vars.mlx);
	return (0);
}