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
	int	i;
	int	**map;
	t_helping_2	helping;

	map = make_numeric_map(text_map);
	helping.max_square = 0;
	i = 0;
	while (i < text_map->height)
	{
		helping.max_square_temp = find_max_square(map[i], text_map->width, &helping.left_index_temp);
		if (helping.max_square < helping.max_square_temp)
		{
			helping.max_square = helping.max_square_temp;
			helping.left_index = helping.left_index_temp;
			helping.top_index = i - helping.max_square_temp + 1;
		}
		i++;
	}
	fill_text_map(text_map, helping.left_index, helping.top_index, helping.max_square);
	free_numeric_map(map, text_map->height);
}

void free_numeric_map(int **map, int count) {
	int	i;

	i = 0;
	while (i < count)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	fill_text_map(t_text_map *text_map, int left_index, int top_index, int square) {
	int	i;
	int	j;

	i = 0;
	while (i < square)
	{
		j = 0;
		while (j < square)
		{
			text_map->map[top_index + i][left_index + j] = text_map->full;
			j++;
		}
		i++;
	}
}

int	find_max_square(int *line, int count, int *left_index) {
	int	square;
	int	max_square;
	t_helping_3	helping;

	helping.li = -1;
	helping.ri = 0;
	helping.h = line[0];
	max_square = 0;

	while (helping.ri < count)
	{
		square = ft_fun9(&helping, line);
		if (max_square < square)
		{
			max_square = square;
			*left_index = helping.li + 1;
		}
		helping.ri++;
	}

	return (max_square);
}

int	ft_fun9(t_helping_3 *helping, int *line) {
	int square;

	if (helping->h > line[helping->ri])
		helping->h = line[helping->ri];

	if (helping->li < helping->ri - helping->h)
	{
		helping->li = helping->ri - helping->h;
		if (helping->li == helping->ri) // <--
			helping->li--;
		if (line[helping->li + 1] < line[helping->ri])
			helping->h = line[helping->li + 1];
		else
			helping->h = line[helping->ri];
	}

	helping->w = helping->ri - helping->li;
	if (helping->w < helping->h)
		square = helping->w;
	else
		square = helping->h;

	return square;
}

int**	make_numeric_map(t_text_map *text_map) {
	int	**map;

	map = alloc_numeric_map(text_map);
	init_numeric_map(text_map, map);
	fill_numeric_map(text_map, map);

	return (map);
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
	return (map);
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

