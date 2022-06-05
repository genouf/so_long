/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 09:58:18 by genouf            #+#    #+#             */
/*   Updated: 2022/06/06 00:41:37 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_border(t_game game)
{
	int	i;

	i = 0;
	while (i < game.nb_cols)
	{
		if (game.map[0][i] != '1' || game.map[game.nb_lines - 1][i] != '1')
			print_error("Error\nThe map is not closed !\n");
		i++;
	}
	i = 0;
	while (i < game.nb_lines)
	{
		if (game.map[i][0] != '1' || game.map[i][game.nb_cols - 1] != '1')
			print_error("Error\nThe map is not closed !\n");
		i++;
	}
}

void	increase_check(t_check *check, char c)
{
	if (c == 'i')
	{
		check->begin = 0;
		check->exit = 0;
		check->items = 0;
	}
	if (c == 'E')
		check->exit++;
	else if (c == 'P')
		check->begin++;
	else if (c == 'C')
		check->items++;
}

void	browse_map(t_game game)
{
	t_check	check;
	int		i;
	int		j;

	i = 1;
	increase_check(&check, 'i');
	while (i < game.nb_lines - 1)
	{
		j = 1;
		while (j < game.nb_cols - 1)
		{
			if (game.map[i][j] == 'E' || game.map[i][j] == 'P'
					|| game.map[i][j] == 'C')
				increase_check(&check, game.map[i][j]);
			else if (game.map[i][j] != '0' && game.map[i][j] != '1')
				print_error("Error\nBad caracter !\n");
			j++;
		}
		i++;
	}
	if (check.begin < 1 || check.exit < 1 || check.items < 1)
		print_error("Error\nOne of the mandatory elements is missing !\n");
	if (check.begin > 1)
		print_error("Error\nMultiple player locations detected !\n");
}

void	check_map(t_game game)
{
	check_border(game);
	browse_map(game);
}
