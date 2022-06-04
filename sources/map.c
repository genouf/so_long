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

int	count_lines(char *pathname)
{
	int		fd;
	int		count;
	char	*tmp;

	fd = open(pathname, O_RDONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
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
	size = ft_strlen(tmp) - 1;
	if (tmp[size] == '\n')
		tmp[size] = '\0';
	*(map[0]) = tmp;
	return (size);
}

char	**init_map(char *pathname, int nb_lines)
{
	char	**map;
	int		fd;
	int		nb_cols;
	int		x;

	fd = open(pathname, O_RDONLY);
	if (fd < 1)
		exit(EXIT_FAILURE);
	map = (char **)malloc(sizeof(char *) * nb_lines);
	if (map == NULL)
		exit(EXIT_FAILURE);
	nb_cols = init_first_line(&map, fd);
	x = 0;
	while (++x < nb_lines)
	{
		map[x] = get_next_line(fd);
		if (x != nb_lines - 1 && map[x][nb_cols] == '\n')
			map[x][nb_cols] = '\0';
	}
	close(fd);
	return (map);
}