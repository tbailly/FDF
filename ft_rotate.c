/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:06:20 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/23 17:14:16 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf.h"

t_point	**ft_rotate_x(t_point **map_to_display, int *map_size, float angle)
{
	float	tmpx;
	float	tmpy;
	float	tmpz;
	int		x;
	int		y;

	x = 0;
	y = 0;
	angle = angle * M_PI / 180;
	while (y < map_size[1])
	{
		while (x < map_size[0])
		{
			tmpx = map_to_display[y][x].x;
			tmpy = map_to_display[y][x].y;
			tmpz = map_to_display[y][x].z;

			// APPLY X ROTATION
			map_to_display[y][x].y = cos(angle) * tmpy - sin(angle) * tmpz;
			map_to_display[y][x].z = sin(angle) * tmpy + cos(angle) * tmpz;
			x++;
		}
		x = 0;
		y++;
	}
	return (map_to_display);
}

t_point	**ft_rotate_y(t_point **map_to_display, int *map_size, float angle)
{
	float	tmpx;
	float	tmpy;
	float	tmpz;
	int		x;
	int		y;

	x = 0;
	y = 0;
	angle = angle * M_PI / 180;
	while (y < map_size[1])
	{
		while (x < map_size[0])
		{
			tmpx = map_to_display[y][x].x;
			tmpy = map_to_display[y][x].y;
			tmpz = map_to_display[y][x].z;

			// APPLY Y ROTATION
			map_to_display[y][x].z = cos(angle) * tmpz - sin(angle) * tmpx;
			map_to_display[y][x].x = sin(angle) * tmpz + cos(angle) * tmpx;


			x++;
		}
		x = 0;
		y++;
	}
	return (map_to_display);
}

t_point	**ft_rotate_z(t_point **map_to_display, int *map_size, float angle)
{
	float	tmpx;
	float	tmpy;
	float	tmpz;
	int		x;
	int		y;

	x = 0;
	y = 0;
	angle = angle * M_PI / 180;
	while (y < map_size[1])
	{
		while (x < map_size[0])
		{
			tmpx = map_to_display[y][x].x;
			tmpy = map_to_display[y][x].y;
			tmpz = map_to_display[y][x].z;

			// APPLY Z ROTATION
			map_to_display[y][x].x = cos(angle) * tmpx - sin(angle) * tmpy;
			map_to_display[y][x].y = sin(angle) * tmpx + cos(angle) * tmpy;

			x++;
		}
		x = 0;
		y++;
	}
	return (map_to_display);
}