/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:59:03 by genouf            #+#    #+#             */
/*   Updated: 2022/06/09 12:55:17 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_coord {
	int	x;
	int	y;
}				t_coord;

typedef struct s_play_g {
	int		step_counter;
	int		items_total;
	int		items_col;
	t_coord	pos_p;
	char	pre_value;
}				t_play_g;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_img_f {
	void	*image;
	int		height;
	int		width;
}			t_img_f;

typedef struct s_game {
	t_vars		vars;
	t_play_g	play;
	char		**map;
	int			nb_lines;
	int			nb_cols;
	t_img_f		telesco;
	t_img_f		tree;
	t_img_f		road;
	t_img_f		straw_bale;
	t_img_f		block;
}				t_game;

typedef struct s_check {
	int	items;
	int	exit;
	int	begin;
}				t_check;
/*		UTILS		*/
int		rgb_to_int(int t, int r, int g, int b);
void	mlx_draw_pixel(t_data *data, int x, int y, int color);
void	init_img(void *mlx, t_game *game);
int		close_prog(t_game *game);
void	init_play_struct(t_play_g *play, t_game game);
/*		ARG_CHECK		*/
void	arg_check(int argc, char *pathname);
void	print_error(char *reason);
/*		MAP		*/
int		count_lines(char *pathname);
t_game	init_map(char *pathname, int nb_lines);
void	free_init_map(char **map, int x, char *reason);
/*		PARSING_MAP		*/
void	check_map(t_game *game);
/*		DRAW_MAP		*/
void	render_map(t_game game);
/*		PLAY		*/
int		monitor(int keycode, t_game *game);
#endif