/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 18:12:57 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/30 23:31:10 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf.h"

t_point	**ft_apply_resizing(t_point **map_to_display, int *map_size, float factor, t_point offset)
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


t_point	**ft_resize(t_point **map_to_display, int *map_size)
{
	float	minx;
	float	miny;
	float	maxx;
	float	maxy;
	int		x;
	int		y;
	float	factor;
	t_point	offset;

	x = 0;
	y = 0;
	minx = WIN_WIDTH;
	miny = WIN_HEIGHT;
	maxx = 0;
	maxy = 0;
	while (y < map_size[1])
	{
		while (x < map_size[0])
		{
			if (map_to_display[y][x].x > maxx)
				maxx = map_to_display[y][x].x;
			if (map_to_display[y][x].x < minx)
				minx = map_to_display[y][x].x;

			if (map_to_display[y][x].y > maxy)
				maxy = map_to_display[y][x].y;
			if (map_to_display[y][x].y < miny)
				miny = map_to_display[y][x].y;
			x++;
		}
		x = 0;
		y++;
	}
	if ((WIN_WIDTH / (maxx - minx)) > (WIN_HEIGHT / (maxy - miny)))
		factor = WIN_HEIGHT / (maxy - miny);
	else
		factor = WIN_WIDTH / (maxx - minx);
	offset.x = (int)ceil(fabs(minx * factor) + WIN_WIDTH / 2 - (maxx * factor - minx * factor) / 2);
	offset.y = (int)ceil(fabs(miny * factor) + WIN_HEIGHT / 2 - (maxy * factor - miny * factor) / 2);
	map_to_display = ft_apply_resizing(map_to_display, map_size, factor, offset);
	return (map_to_display);
}