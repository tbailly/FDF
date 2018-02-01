/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_iso_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:15:45 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 12:02:54 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_create_point_array(int **height_map, int *map_size)
{
	t_point **res;
	int		*color_datas;
	int		color_idx;
	int		x;
	int		y;

	x = 0;
	y = 0;
	color_datas = ft_color_datas();
	if (!(res = (t_point**)malloc(sizeof(t_point*) * map_size[1])))
		exit(0);
	while (y < map_size[1])
	{
		if (!(res[y] = (t_point*)malloc(sizeof(t_point) * map_size[0])))
			exit(0);
		while (x < map_size[0])
		{
			res[y][x].x = x;
			res[y][x].y = y;
			res[y][x].z = height_map[y][x];
			color_idx = (int)(res[y][x].z / 10 + 2);
			if (color_idx < 0)
				color_idx = 0;
			if (color_idx > 12)
				color_idx = 12;
			res[y][x].color = color_datas[color_idx];
			x++;
		}
		x = 0;
		y++;
	}
	return (res);
}

t_point	**ft_apply_iso_matrix(t_point **map_to_display, int *map_size)
{
	map_to_display = ft_rotate_z(map_to_display, map_size, 45);
	map_to_display = ft_rotate_x(map_to_display, map_size, 45);
	ft_resize(map_to_display, map_size);
	return (map_to_display);
}