/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:41:49 by genouf            #+#    #+#             */
/*   Updated: 2022/06/04 09:53:57 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"
#include "../mlx/mlx_int.h"

int	main(int argc, char **argv)
{
	char	**map;

	arg_check(argc, argv[1]);
	map = init_map(argv[1], count_lines(argv[1]));
	int i = 0;
	while (i < 8)
	{
		printf("%s", map[i]);
		printf("\n");
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	/* Initialisation de la mlx */
// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 		exit(EXIT_FAILURE);
		
// 	/* Creation de la fenetre */
// 	mlx_win = mlx_new_window(mlx, 720, 720, "Hello world!");

// 	/* Drawing */
// 	/*mlx_pixel_put(mlx, mlx_win, 0, 100, 0x00FF0000);
// 	mlx_string_put(mlx, mlx_win, 100, 100, 0x00FF0000, "Gabriel");*/
	
// 	/* Creation de l'image */
// 	img.img = mlx_new_image(mlx, 720, 720);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

// 	/* Envoi de l'image et affichage */
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }