/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 19:49:49 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 20:43:50 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

int	ft_fun4(t_helping *helping, t_text_map *map)
{
	if (parameter_check(map) != 0)
	{
		clear_helping(helping);
		free_map(map);
		return (1);
	}
	helping->line = read_line(helping->file, helping->file_count, \
		&(helping->file_offset), &(helping->line_count));
	if (helping->line == NULL)
	{
		clear_helping(helping);
		free_map(map);
		return (1);
	}
	map->width = helping->line_count;
	return (0);
}

int	ft_fun5(t_helping *helping, t_text_map *map)
{
	int	i;

	if (map->width < 1)
	{
		clear_helping(helping);
		free_map(map);
		return (1);
	}
	map->map = malloc(map->height * sizeof(char *));
	i = 0;
	while (i < map->height)
	{
		map->map[i] = NULL;
		i++;
	}
	map->map[0] = helping->line;
	helping->line = NULL;
	return (0);
}

int	ft_fun6(t_helping *helping, t_text_map *map)
{
	int	i;

	i = 0;
	while (i < map->height - 1)
	{
		map->map[1 + i] = read_line(helping->file, helping->file_count, \
			&(helping->file_offset), &(helping->line_count));
		if (map->map[1 + i] == NULL || \
				helping->line_count != map->width)
		{
			clear_helping(helping);
			free_map(map);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_fun7(t_helping *helping, t_text_map *map)
{
	if (helping->file_offset != helping->file_count)
	{
		clear_helping(helping);
		free_map(map);
		return (1);
	}
	return (0);
}

int	ft_fun8(t_helping *helping, t_text_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map[i][j] != map->empty && \
					map->map[i][j] != map->obstacle)
			{
				clear_helping(helping);
				free_map(map);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
