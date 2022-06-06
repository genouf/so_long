/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:41:49 by genouf            #+#    #+#             */
/*   Updated: 2022/06/06 19:38:37 by genouf           ###   ########.fr       */
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
	void		*mlx;
	void		*mlx_win;
	int			nb_cols;
	int			nb_lines;
	int			color;
	t_data		background;
	t_imgbis	telesco;
	t_imgbis	tree;
	t_imgbis	road;
	t_imgbis	straw_bale;
	t_game		game;
	
	arg_check(argc, argv[1]);
	game = init_map(argv[1], count_lines(argv[1]));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 60 * game.nb_cols, 60 * game.nb_lines, "Straw Season");
	draw_bg(mlx, mlx_win, game);
	// telesco.image = mlx_xpm_file_to_image(mlx, "./images/telesco.xpm", &(telesco.width), &(telesco.height));
	// tree.image = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &(tree.width), &(tree.height));
	// road.image = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &(road.width), &(road.height));
	// straw_bale.image = mlx_xpm_file_to_image(mlx, "./images/straw_bale.xpm", &(straw_bale.width), &(straw_bale.height));
	// mlx_put_image_to_window(mlx, mlx_win, telesco.image, 60, 0);
	// mlx_put_image_to_window(mlx, mlx_win, tree.image, 0, 0);
	// mlx_put_image_to_window(mlx, mlx_win, road.image, 120, 0);
	// mlx_put_image_to_window(mlx, mlx_win, straw_bale.image, 180, 0);
	mlx_loop(mlx);
	return (0);	
}