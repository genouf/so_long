/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:07 by genouf            #+#    #+#             */
/*   Updated: 2022/06/09 15:28:03 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error(char *reason)
{
	ft_putstr_fd(reason, 2);
	exit(EXIT_FAILURE);
}

void	check_hidden_f(char *pathname)
{
	char	*slash_add;

	slash_add = ft_strrchr(pathname, '/');
	if ((slash_add == NULL && pathname[0] == '.') || (slash_add
			&& slash_add[1] == '.'))
		print_error("Error\nHidden files not supported !\n");
}

void	img_validity(char *path, int *check)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		*check = 0;
	close(fd);
}

void	check_imgs(void)
{
	int	check;

	check = 1;
	img_validity("images/telesco.xpm", &check);
	img_validity("images/tree.xpm", &check);
	img_validity("images/road.xpm", &check);
	img_validity("images/straw_bale.xpm", &check);
	img_validity("images/block.xpm", &check);
	if (check == 0)
		print_error("Error\n An image isn't valid !\n");
}

void	arg_check(int argc, char *pathname)
{
	int	size;
	int	fd;

	if (argc != 2)
		print_error("Error\nWrong number of arguments !\n");
	check_hidden_f(pathname);
	size = ft_strlen(pathname) - 4;
	if (ft_strncmp(pathname + size, ".ber", 4) != 0)
		print_error("Error\nWrong file type given !\n");
	fd = open(pathname, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
		print_error("Error\nYou try to open a directory !\n");
	close(fd);
	check_imgs();
}
