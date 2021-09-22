/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 05:47:15 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 19:49:24 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

t_text_map    *read_map(int fd)
{
	struct s_helping    helping;
	t_text_map    *map;

	if (ft_fun1(&helping.file_offset, fd, &helping.file_count, &helping.file))
		return (NULL);
	if (ft_fun2(&helping))
		return (NULL);
	if (ft_fun3(&map, &helping))
		return (NULL);
	if (ft_fun4(&helping, &map))
		return (NULL);
	if (ft_fun5 (&map, &helping))
		return (NULL);
	if (ft_fun6 (&map, &helping))
		return (NULL);
	if (ft_fun7 (&map, &helping))
		return (NULL);
	if (ft_fun8 (&map, &helping))
		return (NULL);
	return (map);
}

int	ft_fun1(int *file_offset, int fd, int *file_count, char **file)
{
	*file_offset = 0;
	*file = read_file(fd, file_count);
	if (*file == NULL)
		return (1);
	if (*file_count == 0)
	{
		free(*file);
		return (1);
	}
	return (0);
}

int	ft_fun2(t_helping *helping)
{
	helping->line = read_line(helping->file, helping->file_count, &(helping->file_offset), &(helping->line_count));
	if (helping->line == NULL)
	{
		free(helping->file);
		return (1);
	}
	if (helping->line_count < 4)
	{
		free(helping->file);
		free(helping->line);
		return (1);
	}
	return (0);
}

int	ft_fun3(t_text_map **map, t_helping *helping)
{
	*map = malloc(sizeof(t_text_map));
	if (*map == NULL)
	{
		free(helping->file);
		free(helping->line);
		return (1);
	}
	(*map)->map = NULL;
	(*map)->full = helping->line[helping->line_count - 1];
	(*map)->obstacle = helping->line[helping->line_count - 2];
	(*map)->empty = helping->line[helping->line_count - 3];
	helping->line[helping->line_count - 3] = '\0';
	(*map)->height = bsq_atoi(helping->line);
	free(helping->line);
	return (0);
}


