/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_iso_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:15:45 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/15 23:54:22 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "fdf.h"

t_point	**ft_apply_iso_matrix(int **height_map, int *map_size)
{
	t_point **res;
	int		x;
	int		y;
	float	tmpx;
	float	tmpy;

	x = 0;
	y = 0;
	res = (t_point**)malloc(sizeof(t_point*) * map_size[1]);

	while (y < map_size[1])
	{
		res[y] = (t_point*)malloc(sizeof(t_point) * map_size[0]);
		while (x < map_size[0])
		{
			//printf("res %f\n", sqrt(2)/2 * 2);
			tmpx = sqrt(2)/2 * (x - y) * 50 + 1000;
			tmpy = (sqrt((float)2/3) * height_map[y][x]) - (1/sqrt(6) * (x + y)) * 50 + 1000;
			res[y][x].x = (int)round(tmpx);
			res[y][x].y = (int)round(tmpy);
			//printf("AAAAAAA sqrt(2/3) %f et height_map[y][x] %i \n", sqrt((float)2/3), height_map[y][x]);
			//printf("AAAAAAA (sqrt(2/3) * height_map[y][x]) %f\n", (sqrt((float)2/3) * height_map[y][x]));
			printf("----- %f ----- %i ----- %i \n", tmpy, res[y][x].y, height_map[y][x]);
			//printf("res[%i][%i].x = %i \n", y, x, res[y][x].x);
			//printf("res[%i][%i].y = %i \n", y, x, res[y][x].y);
			x++;
		}
		x = 0;
		y++;
	}
	return (res);
}