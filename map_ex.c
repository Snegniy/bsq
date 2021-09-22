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

int	ft_fun4(t_helping *helping, t_text_map **map)
{
	if (parameter_check(*map) != 0)
	{
		free(helping->file);
		free_map(*map, 0);
		return (NULL);
	}
	helping->line = read_line(helping->file, helping->file_count, \
		&(helping->file_offset), &(helping->line_count));
	if (helping->line == NULL)
	{
		free(helping->file);
		free_map(*map, 0);
		return (NULL);
	}
	(*map)->width = helping->line_count;
	return (0);
}

int	ft_fun5(t_text_map **map, t_helping *helping)
{
	if ((*map)->width < 1)
	{
		free(helping->file);
		free(helping->line);
		free_map(*map, 0);
		return (NULL);
	}
	(*map)->map = malloc((*map)->height * sizeof(char *));
	(*map)->map[0] = helping->line;
	helping->valid_line_count = 1;
	return (0);
}

int	ft_fun6(t_text_map **map, t_helping *helping)
{
	int	i;

	i = 0;
	while (i < (*map)->height - 1)
	{
		(*map)->map[1 + i] = read_line(helping->file, helping->file_count, \
			&(helping->file_offset), &(helping->line_count));
		if ((*map)->map[1 + i] == NULL)
		{
			free(helping->file);
			free(helping->line);
			free_map(*map, helping->valid_line_count);
			return (NULL);
		}
		helping->valid_line_count++;
		if (helping->line_count != (*map)->width)
		{
			free(helping->file);
			free(helping->line);
			free_map(*map, helping->valid_line_count);
			return (NULL);
		}
		i++;
	}
	return (0);
}

int	ft_fun7(t_text_map **map, t_helping *helping)
{
	if (helping->file_offset != helping->file_count)
	{
		free(helping->file);
		free(helping->line);
		free_map(*map, (*map)->height);
		return (NULL);
	}
	return (0);
}

int	ft_fun8(t_text_map **map, t_helping *helping)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->width)
		{
			if ((*map)->map[i][j] != (*map)->empty && \
					(*map)->map[i][j] != (*map)->obstacle)
			{
				free(helping->file);
				free(helping->line);
				free_map(*map, helping->valid_line_count);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (0);
}
