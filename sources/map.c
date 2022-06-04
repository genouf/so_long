/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:18:05 by genouf            #+#    #+#             */
/*   Updated: 2022/06/03 11:18:14 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_init_map(char **map, int x, char *reason)
{
	while (x > -1)
	{
		free(map[x]);
		x--;
	}
	free(map);
	print_error(reason);
}

int	count_lines(char *pathname)
{
	int		fd;
	int		count;
	char	*tmp;

	fd = open(pathname, O_RDONLY);
	if (fd < 1)
		print_error("Error\nBad File Descriptor !\n");
	tmp = get_next_line(fd);
	count = 0;
	while (tmp)
	{
		count++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	init_first_line(char ***map, int fd)
{
	char	*tmp;
	int		size;

	tmp = get_next_line(fd);
	if (tmp == NULL)
		free_init_map(*map, -1, "Malloc Error !\n");
	size = ft_strlen(tmp) - 1;
	if (tmp[size] == '\n')
		tmp[size] = '\0';
	*(map[0]) = tmp;
	return (size);
}

int	begin_init_map(t_game *game, char *pathname, int nb_lines)
{
	int	fd;

	game->nb_lines = nb_lines;
	fd = open(pathname, O_RDONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
	game->map = (char **)malloc(sizeof(char *) * nb_lines);
	if (game->map == NULL)
		free_init_map(game->map, -1, "Malloc Error !\n");
	return (fd);
}

t_game	init_map(char *pathname, int nb_lines)
{
	t_game	game;
	int		fd;
	int		x;

	fd = begin_init_map(&game, pathname, nb_lines);
	game.nb_cols = init_first_line(&(game.map), fd);
	if (game.nb_cols == game.nb_lines)
		free_init_map(game.map, 0, "Error\nThe Map is not a rectangle !\n");
	x = 0;
	while (++x < nb_lines)
	{
		game.map[x] = get_next_line(fd);
		if (game.map[x] == NULL)
			free_init_map(game.map, x - 1, "Malloc Error !\n");
		if (ft_strlen(game.map[x]) != game.nb_cols + 1)
			free_init_map(game.map, x, "Error\nThe Map is not a rectangle !\n");
		if (x != nb_lines - 1 && game.map[x][game.nb_cols] == '\n')
			game.map[x][game.nb_cols] = '\0';
	}
	close(fd);
	return (game);
}
