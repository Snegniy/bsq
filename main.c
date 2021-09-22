/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:10:10 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 20:33:11 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*filepath;

	if (argc == 1)
	{
		filepath = "./map_user";
		standard_input(filepath);
		process_file(filepath);
	}
	else
	{
		i = 0;
		while (++i < argc)
		{
			process_file(argv[i]);
		}
	}
	sleep(1000);
	return (0);
}

void	standard_input(char *file_path)
{
	char	buf[1];
	int		fd;

	fd = open(file_path, O_TRUNC | O_WRONLY | O_CREAT, 0666);
	while (read(0, buf, 1))
	{
		write(fd, &buf, 1);
	}
	close(fd);
}

void	process_file(char *file_path)
{
	int			i;
	int			fd;
	t_text_map	*map;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		error();
	else
	{
		map = read_map(fd);
		if (map == NULL)
			error();
		else
		{
			process_map(map);
			i = 0;
			while (i < map->height)
			{
				write(1, map->map[i++], map->width);
				write(1, "\n", 1);
			}
			free_map(map, map->height);
		}
		close(fd);
	}
}

void	error(void)
{
	write(2, "map error\n", 10);
}
