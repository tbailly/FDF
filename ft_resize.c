/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:12:57 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 11:28:36 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**ft_apply_resizing(t_point **map_to_display, int *map_size, float factor, t_point offset)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map_size[1])
	{
		while (x < map_size[0])
		{
			map_to_display[y][x].x = map_to_display[y][x].x * factor + offset.x;
			map_to_display[y][x].y = map_to_display[y][x].y * factor + offset.y;
			x++;
		}
		x = 0;
		y++;
	}
	return (map_to_display);
}

static t_bounds	ft_find_bounds(t_bounds bounds, t_point **map_to_display, int *map_size)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < map_size[1])
	{
		while (x < map_size[0])
		{
			if (map_to_display[y][x].x > bounds.maxx)
				bounds.maxx = map_to_display[y][x].x;
			if (map_to_display[y][x].x < bounds.minx)
				bounds.minx = map_to_display[y][x].x;

			if (map_to_display[y][x].y > bounds.maxy)
				bounds.maxy = map_to_display[y][x].y;
			if (map_to_display[y][x].y < bounds.miny)
				bounds.miny = map_to_display[y][x].y;
			x++;
		}
		x = 0;
		y++;
	}
	return (bounds);
}

t_point	**ft_resize(t_point **map_to_display, int *map_size)
{
	t_bounds bounds;	
	float	factor;
	t_point	offset;

	bounds.minx = WIN_WIDTH;
	bounds.miny = WIN_HEIGHT;
	bounds.maxx = 0;
	bounds.maxy = 0;
	bounds = ft_find_bounds(bounds, map_to_display, map_size);
	if ((WIN_WIDTH / (bounds.maxx - bounds.minx)) > (WIN_HEIGHT / (bounds.maxy - bounds.miny)))
		factor = WIN_HEIGHT / (bounds.maxy - bounds.miny);
	else
		factor = WIN_WIDTH / (bounds.maxx - bounds.minx);
	offset.x = (int)ceil(fabs(bounds.minx * factor) + WIN_WIDTH / 2 - (bounds.maxx * factor - bounds.minx * factor) / 2);
	offset.y = (int)ceil(fabs(bounds.miny * factor) + WIN_HEIGHT / 2 - (bounds.maxy * factor - bounds.miny * factor) / 2);
	map_to_display = ft_apply_resizing(map_to_display, map_size, factor, offset);
	return (map_to_display);
}