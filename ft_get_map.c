/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:12 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/24 21:42:22 by tbailly-         ###   ########.fr       */
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

static	void	ft_debug_print_height_map(int **height_map, int *map_size)
{
	int	i;
	int	j;

	i = 0;
	printf("-------- height_map --------\n");
	while (i < map_size[1])
	{
		j = 0;
		while (j < map_size[0])
		{
			printf("%i ", height_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n\n");
}

int			**ft_get_height_map(char *filename, int **map_size_pt)
{
	int				fd;
	char			**line;
	char			**entries;
	int				**height_map;

	line = (char**)malloc(sizeof(char*));
	*map_size_pt = (int*)malloc(sizeof(int*) * 2);
	(*map_size_pt)[0] = 0;
	(*map_size_pt)[1] = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, line) == 1)
	{
		(*map_size_pt)[1]++;
		entries = ft_strsplit(*line, ' ');
		//printf("{%i}\n", (*map_size_pt)[1]);
		ft_get_height_row(entries);
		height_map = ft_add_row_height_map(height_map, ft_get_height_row(entries), (*map_size_pt)[1]);
		//ft_free_strarr(entries);
		//free(*line);
	}
	free(*line);
	free(line);
	while (entries[(*map_size_pt)[0]] != NULL)
		(*map_size_pt)[0]++;
	//ft_debug_print_height_map(height_map, *map_size_pt);
	return (height_map);
}








