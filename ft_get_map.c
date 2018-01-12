/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:12 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/12 15:11:16 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "fdf.h"

static	int	*ft_get_height_row(char **str_row)
{
	int	i;
	int	*map_row;

	i = 0;
	while (str_row[i] != NULL)
		i++;
	map_row = (int*)malloc(sizeof(int*) * i + 1);
	i = 0;
	while (str_row[i] != NULL)
	{
		map_row[i] = ft_atoi(str_row[i]);
		i++;
	}
	return (map_row);
}

static	int	**ft_add_row_height_map(int **height_map, int *map_row, int nb_row)
{
	int	i;
	int	**res;

	i = 0;
	res = (int**)malloc(sizeof(int**) * nb_row);
	while (i < nb_row - 1)
	{
		res[i] = height_map[i];
		i++;
	}
	res[i] = map_row;
	//TODO memory not allocated donc je sais pas, bon...
	//free(height_map);
	return (res);
}

int			**ft_get_height_map(char *filename)
{
	int				fd;
	char			*line;
	char			**entries;
	int				**height_map;
	int				nb_row;

	nb_row = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		nb_row++;
		entries = ft_strsplit(line, ' ');
		height_map = ft_add_row_height_map(height_map, ft_get_height_row(entries), nb_row);
	}
	return (height_map);
}