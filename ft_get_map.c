/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:12 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 21:58:32 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	*ft_get_height_row(char **str_row, int **map_size_pt)
{
	int	i;
	int	*map_row;

	i = 0;
	if (str_row[0] == NULL)
		ft_exit_message("No datas found.");
	if ((*map_size_pt)[0] == 0)
		while (str_row[(*map_size_pt)[0]] != NULL)
			(*map_size_pt)[0]++;
	if (!(map_row = (int*)malloc(sizeof(int*) * (*map_size_pt)[0])))
		ft_exit("ft_get_height_row");
	while (i < (*map_size_pt)[0] || str_row[i] != NULL)
	{
		if (i > (*map_size_pt)[0] || str_row[i] == NULL)
			ft_exit_message("Found wrong line length.");
		map_row[i] = ft_atoi(str_row[i]);
		i++;
	}
	return (map_row);
}

static	int	**ft_add_row_height_map(int **height_map, int *map_row, int *map_size)
{
	int	i;
	int	j;
	int	**res;

	i = 0;
	if (!(res = (int**)malloc(sizeof(int*) * map_size[1])))
		ft_exit("ft_add_row_height_map");
	while (i < map_size[1])
	{
		if (!(res[i] = (int*)malloc(sizeof(int) * map_size[0])))
			ft_exit("ft_add_row_height_map");
		j = 0;
		while (j < map_size[0])
		{
			if (i < map_size[1] - 1)
				res[i][j] = height_map[i][j];
			else
				res[i][j] = map_row[j];
			j++;
		}
		if (i < map_size[1] - 1)
			free(height_map[i]);
		else
			free(map_row);
		i++;
	}
	free(height_map);
	return (res);
}

int			**ft_get_height_map(char *filename, int **map_size_pt)
{
	int				fd;
	char			**line;
	char			**entries;
	int				**height_map;

	height_map = NULL;
	if (!(line = (char**)malloc(sizeof(char*))) ||
			(!(*map_size_pt = (int*)malloc(sizeof(int*) * 2))))
		ft_exit("ft_get_height_map");
	(*map_size_pt)[0] = 0;
	(*map_size_pt)[1] = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, line) == 1)
	{
		(*map_size_pt)[1]++;
		entries = ft_strsplit(*line, ' ');
		height_map = ft_add_row_height_map(height_map, ft_get_height_row(entries, map_size_pt), (*map_size_pt));
		ft_free_strarr(entries);
		free(*line);
	}
	if ((*map_size_pt)[1] == 0)
		ft_exit_message("No datas found.");
	close(fd);
	free(*line);
	free(line);
	return (height_map);
}
