/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 05:42:47 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 05:47:03 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/bsq.h"

int	bsq_atoi(char *str)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (str[i] == '0')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		number = number * 10 + (str[i] - '0');
		i++;
	}
	return (number);
}

int	parameter_check(t_text_map *map)
{
	if (map->height < 1)
		return (1);
	if (map->full < 32 || map->full > 126)
		return (1);
	if (map->empty < 32 || map->empty > 126)
		return (1);
	if (map->obstacle < 32 || map->obstacle > 126)
		return (1);
	if (map->empty == map->obstacle || map->empty == map->full || \
	map->obstacle == map->full)
		return (1);
	return (0);
}
