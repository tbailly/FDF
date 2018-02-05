/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_h_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:35:12 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 11:53:16 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_check_line_string(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' && s[i] != ' ' && s[i] != ','
			&& s[i] != '+' && s[i] != '-') ||
			(s[i] > '9' && s[i] < 'A') ||
			(s[i] > 'F' && s[i] < 'a') ||
			(s[i] > 'f' && s[i] != 'x'))
			ft_exit_message("Forbidden character found.");
		i++;
	}
}

static	int	*ft_get_h_row(char **str_row, int **map_size_pt)
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
		ft_exit("ft_get_h_row");
	while (i < (*map_size_pt)[0] || str_row[i] != NULL)
	{
		if (i > (*map_size_pt)[0] || str_row[i] == NULL)
			ft_exit_message("Found wrong line length.");
		ft_check_line_string(str_row[i]);
		map_row[i] = ft_atoi(str_row[i]);
		i++;
	}
	return (map_row);
}

static void	ft_free_last(int **h_map, int *map_row, int *map_size, int i)
{
	if (i < map_size[1] - 1)
		free(h_map[i]);
	else
		free(map_row);
}

static	int	**ft_add_row_h_map(int **h_map, int *map_row, int *map_size)
{
	int	i;
	int	j;
	int	**res;

	i = 0;
	if (!(res = (int**)malloc(sizeof(int*) * map_size[1])))
		ft_exit("ft_add_row_h_map");
	while (i < map_size[1])
	{
		if (!(res[i] = (int*)malloc(sizeof(int) * map_size[0])))
			ft_exit("ft_add_row_h_map");
		j = 0;
		while (j < map_size[0])
		{
			if (i < map_size[1] - 1)
				res[i][j] = h_map[i][j];
			else
				res[i][j] = map_row[j];
			j++;
		}
		ft_free_last(h_map, map_row, map_size, i);
		i++;
	}
	free(h_map);
	return (res);
}

int			**ft_get_h_map(char *filename, int **map_size_pt)
{
	int				fd;
	char			**line;
	char			**entries;
	int				**h_map;

	h_map = NULL;
	if (!(line = (char**)malloc(sizeof(char*))))
		ft_exit("ft_get_h_map");
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, line) == 1)
	{
		(*map_size_pt)[1]++;
		entries = ft_strsplit(*line, ' ');
		h_map = ft_add_row_h_map(h_map, ft_get_h_row(entries, map_size_pt),
				(*map_size_pt));
		ft_free_strarr(entries);
		free(*line);
	}
	if ((*map_size_pt)[1] == 0 || (*map_size_pt)[1] == 1)
		ft_exit_message("No datas found.");
	close(fd);
	free(*line);
	free(line);
	return (h_map);
}
