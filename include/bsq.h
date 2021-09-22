/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imelody <imelody@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 14:48:03 by imelody           #+#    #+#             */
/*   Updated: 2021/09/22 20:46:48 by imelody          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_text_map
{
	int		width;
	int		height;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
}	t_text_map;

typedef struct s_helping
{
	char	*file;
	char	*line;
	int		file_offset;
	int		file_count;
	int		line_count;
}	t_helping;

void		standard_input(char *file_path);
void		process_file(char *file_path);
t_text_map	*read_map(int fd);
void		process_map(t_text_map *map);
int			parameter_check(t_text_map *map);
void		free_map(t_text_map *map);
void		clear_helping(t_helping *helping);
char		*read_file(int fd, int *count);
char		*read_line(char *text, int text_count, int *text_offset, \
					   int *line_count);
void		memory_copy_1(char *src, char *dst, int dst_offset, int count);
void		memory_copy_2(char *src, char *dst, int src_offset, int count);
int			bsq_atoi(char *str);
void		error(void);
int			ft_fun1(t_helping *helping, int fd);
int			ft_fun2(t_helping *helping);
int			ft_fun3(t_helping *helping, t_text_map **map);
int			ft_fun4(t_helping *helping, t_text_map *map);
int			ft_fun5(t_helping *helping, t_text_map *map);
int			ft_fun6(t_helping *helping, t_text_map *map);
int			ft_fun7(t_helping *helping, t_text_map *map);
int			ft_fun8(t_helping *helping, t_text_map *map);

int**	make_numeric_map(t_text_map *text_map);
int**	alloc_numeric_map(t_text_map *text_map);
void	init_numeric_map(t_text_map *text_map, int **map);
void	fill_numeric_map(t_text_map *text_map, int **map);

#endif
