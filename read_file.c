/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 05:45:45 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 06:33:02 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

char	*read_line(char *text, int text_count, int *text_offset, \
			int *line_count)
{
	int		i;
	char	*result;

	i = 0;
	while (*text_offset + i < text_count && text[*text_offset + i] != '\n')
		i++;
	if (*text_offset + i == text_count - 1 && text[*text_offset + i] != '\n')
		return (NULL);
	*line_count = i;
	result = malloc(*line_count * sizeof(char));
	memory_copy_2(text, result, *text_offset, *line_count);
	*text_offset += *line_count + 1;
	return (result);
}

void	memory_copy_1(char *src, char *dst, int dst_offset, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		dst[dst_offset + i] = src[i];
		i++;
	}
}

void	memory_copy_2(char *src, char *dst, int src_offset, int count)
{
	int		i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[src_offset + i];
		i++;
	}
}

void	free_map(t_text_map *map)
{
	int		i;

	if (map->map != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->map[i] != NULL)
			{
				free(map->map[i]);
				map->map[i] = NULL;
			}
			else
				break;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
	free(map);
}

void	clear_helping(t_helping *helping)
{
	if (helping->file != NULL)
	{
		free(helping->file);
		helping->file = NULL;
	}

	if (helping->line != NULL)
	{
		free(helping->line);
		helping->line = NULL;
	}

	helping->file_count = 0;
	helping->line_count = 0;
	helping->file_offset = 0;
}

char	*read_file(int fd, int *count)
{
	int		read_count;
	char	buf[8192];
	char	*temp;
	char	*result;

	*count = 0;
	result = NULL;
	read_count = read(fd, &buf, (sizeof(buf) / sizeof(char)));
	while (read_count > 0)
	{
		*count += read_count;
		temp = malloc(*count * sizeof(char));
		memory_copy_1(result, temp, 0, *count - read_count);
		memory_copy_1(buf, temp, *count - read_count, read_count);
		if (result != NULL)
			free(result);
		result = temp;
		read_count = read(fd, &buf, (sizeof(buf) / sizeof(char)));
	}
	return (result);
}
