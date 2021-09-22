/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 05:47:15 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 20:36:55 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

t_text_map	*read_map(int fd)
{
	t_helping	helping;
	t_text_map			*map;

	helping.file = NULL;
	helping.line = NULL;
	if (ft_fun1(&helping, fd))
		return (NULL);
	if (ft_fun2(&helping))
		return (NULL);
	if (ft_fun3(&helping, &map))
		return (NULL);
	if (ft_fun4(&helping, map))
		return (NULL);
	if (ft_fun5(&helping, map))
		return (NULL);
	if (ft_fun6(&helping, map))
		return (NULL);
	if (ft_fun7(&helping, map))
		return (NULL);
	if (ft_fun8(&helping, map))
		return (NULL);
	return (map);
}

int	ft_fun1(t_helping* helping, int fd)
{
	helping->file_offset = 0;
	helping->file = read_file(fd, &(helping->file_count));
	if (helping->file == NULL)
		return (1);
	if (helping->file_count == 0)
	{
		clear_helping(helping);
		return (1);
	}
	return (0);
}

int	ft_fun2(t_helping *helping)
{
	helping->line = read_line(helping->file, helping->file_count, \
		&(helping->file_offset), &(helping->line_count));
	if (helping->line == NULL)
	{
		clear_helping(helping);
		return (1);
	}
	if (helping->line_count < 4)
	{
		clear_helping(helping);
		return (1);
	}
	return (0);
}

int	ft_fun3(t_helping *helping, t_text_map **map)
{
	*map = malloc(sizeof(t_text_map));
	if (*map == NULL)
	{
		clear_helping(helping);
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
