/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 05:15:01 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 18:42:57 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

void	process_map(t_text_map *text_map)
{
	int	s;
	int	i;
	int	j;
	int	**map;

	map = make_numeric_map(text_map);

	int	maxSquare;
	int	leftIndex;
	int	topIndex;

	maxSquare = 0;
	i = 0;
	while (i < text_map->height)
	{
		int	li = -1;
		int	ri = 0;
		int	h;
		h = map[i][0];

		while (ri < text_map->width)
		{
			if (h > map[i][ri])
				h = map[i][ri];

			if (li < ri - h)
			{
				li = ri - h;
				if (li == ri) // <--
					li--;
				if (map[i][li + 1] < map[i][ri])
					h = map[i][li + 1];
				else
					h = map[i][ri];
			}
			int	w;

			w = ri - li;
			if (w < h)
				s = w;
			else
				s = h;
			if (maxSquare < s)
			{
				maxSquare = s;
				leftIndex = li + 1;
				topIndex = i - s + 1;
			}
			ri++;
		}
		i++;
	}
	i = 0;
	while (i < maxSquare)
	{
		j = 0;
		while (j < maxSquare)
		{
			text_map->map[topIndex + i][leftIndex + j] = text_map->full;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < text_map->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int**	make_numeric_map(t_text_map *text_map) {
	int	**map;

	map = alloc_numeric_map(text_map);
	init_numeric_map(text_map, map);
	fill_numeric_map(text_map, map);
}

int**	alloc_numeric_map(t_text_map *text_map) {
	int	i;
	int	j;
	int	**map;

	map = malloc(text_map->height * sizeof(int *));
	i = 0;
	while (i < text_map->height)
	{
		map[i] = malloc(text_map->width * sizeof(int));
		i++;
	}
	i = 0;
	while (i < text_map->height)
	{
		j = 0;
		while (j < text_map->width)
		{
			map[i][j] = text_map->map[i][j] == text_map->empty;
			j++;
		}
		i++;
	}
	return map;
}

void	init_numeric_map(t_text_map *text_map, int **map) {
	int	i;
	int	j;

	i = 0;
	while (i < text_map->height)
	{
		j = 0;
		while (j < text_map->width)
		{
			map[i][j] = text_map->map[i][j] == text_map->empty;
			j++;
		}
		i++;
	}
}

void fill_numeric_map(t_text_map *text_map, int **map) {
	int	i;
	int	j;

	i = 1;
	while (i < text_map->height)
	{
		j = 0;
		while (j < text_map->width)
		{
			if (map[i][j] == 1)
				map[i][j] += map[i - 1][j];
			j++;
		}
		i++;
	}
}

