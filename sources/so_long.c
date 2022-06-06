/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:41:49 by genouf            #+#    #+#             */
/*   Updated: 2022/06/06 18:34:09 by genouf           ###   ########.fr       */
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

int	main(void)
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
	
	color = rgb_to_int(0, 235, 213, 173); 
	nb_cols = 10;
	nb_lines = 4;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 60*nb_cols, 60*nb_lines, "Telesco");
	background.img = mlx_new_image(mlx, 60*nb_cols, 60*nb_lines);
	background.addr = mlx_get_data_addr(background.img, &background.bits_per_pixel, &background.line_length, &background.endian);
	int	i = 0;
	int j = 0;
	mlx_draw_pixel(&background, i, j, color);
	while (i < 60 * nb_lines + 1)
	{
		j = 0;
		while (j < 60 * nb_cols + 1)
		{
			mlx_draw_pixel(&background, j, i, color);
			j++;
		}
		i++;
	}
	telesco.image = mlx_xpm_file_to_image(mlx, "./images/telesco.xpm", &(telesco.width), &(telesco.height));
	tree.image = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &(tree.width), &(tree.height));
	road.image = mlx_xpm_file_to_image(mlx, "./images/road.xpm", &(road.width), &(road.height));
	straw_bale.image = mlx_xpm_file_to_image(mlx, "./images/straw_bale.xpm", &(straw_bale.width), &(straw_bale.height));
	mlx_put_image_to_window(mlx, mlx_win, background.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, telesco.image, 60, 0);
	mlx_put_image_to_window(mlx, mlx_win, tree.image, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, road.image, 120, 0);
	mlx_put_image_to_window(mlx, mlx_win, straw_bale.image, 180, 0);
	mlx_loop(mlx);
	return (0);	
}