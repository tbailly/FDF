/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_point_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 09:37:33 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 10:48:00 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	ft_set_point(t_point point, int *color_datas, int x, int y)
{
	int		color_idx;

	color_idx = (int)(point.z / 10 + 2);
	if (color_idx < 0)
		color_idx = 0;
	if (color_idx > 12)
		color_idx = 12;
	point.color = color_datas[color_idx];
	point.x = x;
	point.y = y;
	return (point);
}

t_point			**ft_create_point_array(int **h_map, int *map_size)
{
	t_point **res;
	int		*color_datas;
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
			res[y][x].z = h_map[y][x];
			res[y][x] = ft_set_point(res[y][x], color_datas, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	free(color_datas);
	return (res);
}
