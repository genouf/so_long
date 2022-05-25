/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: genouf <genouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:45:29 by genouf            #+#    #+#             */
/*   Updated: 2022/05/25 17:42:45 by genouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*result;
	unsigned char	*p;
	size_t			buff_size;

	buff_size = count * size;
	result = (void *)malloc(buff_size);
	if (result == NULL)
		return (NULL);
	p = (unsigned char *)result;
	while (buff_size > 0)
	{
		*p = 0;
		p++;
		buff_size--;
	}
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size;
	char	*result;
	int		i;
	int		j;

	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	result = (char *)ft_calloc_gnl(sizeof(char), size);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s1 && s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		result[i] = s2[j];
		j++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

void	ft_substr(char *s, unsigned int start, char *save)
{
	size_t	i;
	size_t	size;

	start++;
	size = ft_strlen_gnl(s + start);
	i = 0;
	if (size == 0)
		return ;
	while (s[start] != '\0')
	{
		save[i] = s[start];
		i++;
		start++;
	}
}

char	*ft_subuff(char *buff, int id_line)
{
	char	*result;
	int		i;

	result = (char *)ft_calloc_gnl(sizeof(char), (id_line + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < id_line + 1)
	{
		result[i] = buff[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
