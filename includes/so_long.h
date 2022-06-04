/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 22:59:03 by genouf            #+#    #+#             */
/*   Updated: 2022/06/04 09:57:45 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*		UTILS		*/
int		rgb_to_int(int t, int r, int g, int b);
void	mlx_draw_pixel(t_data *data, int x, int y, int color);
/*		ARG_CHECK		*/
void	arg_check(int argc, char *pathname);
/*		MAP		*/
int		count_lines(char *pathname);
char	**init_map(char *pathname, int nb_lines);

#endif