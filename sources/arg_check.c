/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:04:07 by genouf            #+#    #+#             */
/*   Updated: 2022/06/03 10:44:51 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_hidden_f(char *pathname)
{
	char	*slash_add;

	slash_add = ft_strrchr(pathname, '/');
	if ((slash_add == NULL && pathname[0] == '.') || (slash_add
			&& slash_add[1] == '.'))
	{
		ft_putstr_fd("Error\nHidden files not supported !\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	arg_check(int argc, char *pathname)
{
	int	size;
	int	fd;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nWrong number of arguments !\n", 2);
		exit(EXIT_FAILURE);
	}
	check_hidden_f(pathname);
	size = ft_strlen(pathname) - 4;
	if (ft_strncmp(pathname + size, ".ber", 4) != 0)
	{
		ft_putstr_fd("Error\nWrong file type given !\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(pathname, O_RDONLY | O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error\nYou try to open a directory !\n", 2);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
