/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:42:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/24 23:01:23 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void	ft_debug_print_point_array(t_point **map_to_display, int *map_size)
{
	int	x;
	int	y;

	y = 0;
	while (y < map_size[1])
	{
		x = 0;
		while (x < map_size[0])
		{
			printf("%i;%i;%i || ", (int)map_to_display[y][x].x, (int)map_to_display[y][x].y, (int)map_to_display[y][x].z);
			x++;
		}
		printf("\n");
		y++;
	}
}


static	t_int_point	get_direction(t_int_point p1, t_int_point p2)
{
	int sub;
	int sub_abs;
	t_int_point	res;
	
	sub = p2.x - p1.x;
	sub_abs = ft_abs(sub);
	res.x = (sub == 0) ? 0 : (sub / sub_abs);
	
	sub = p2.y - p1.y;
	sub_abs = ft_abs(sub);
	res.y = (sub == 0) ? 0 : (sub / sub_abs);
	return (res);
}

void			draw_line(void *mlx, void *win, t_int_point p1, t_int_point p2)
{
	int	a;
	int	b;
	int	p;
	int x_longer_than_y;
	t_int_point	direction;
	t_int_point ptemp;

	//printf("draw_line ----- p1: %i;%i ----- p2: %i;%i\n", p1.x, p1.y, p2.x, p2.y);
	direction = get_direction(p1, p2);
	if (ft_abs(p1.x - p2.x) > ft_abs(p1.y - p2.y))
	{
		a = 2 * (ft_abs(p1.y - p2.y));
		b = a - (2 * (ft_abs(p1.x - p2.x)));
		p = a - ft_abs(p1.x - p2.x);
		x_longer_than_y = 1;
	}
	else
	{
		a = 2 * (ft_abs(p1.x - p2.x));
		b = a - (2 * (ft_abs(p1.y - p2.y)));
		p = a - ft_abs(p1.y - p2.y);
		x_longer_than_y = 0;
	}

	ptemp.x = p1.x;
	ptemp.y = p1.y;

	while (ptemp.x != p2.x || ptemp.y != p2.y)
	{
		//printf("ptemp %i;%i et p2 %i;%i\n", (int)ptemp.x, (int)ptemp.y, (int)p2.x, (int)p2.y);
		mlx_pixel_put(mlx, win, ptemp.x, ptemp.y, 0x00FFFFFF);
		if (x_longer_than_y)
		{
			ptemp.x += 1 * direction.x;
			if ((p >= 0))
				ptemp.y += 1 * direction.y;
		}
		else
		{
			ptemp.y += 1 * direction.y;
			if ((p >= 0))
				ptemp.x += 1 * direction.x;
		}
		p = (p >= 0) ? (p + b) :(p + a);
	}
	//printf("draw_line ----- p1: %i;%i ----- p2: %i;%i\n", (int)p1.x, (int)p1.y, (int)p2.x, (int)p2.y);
}

/*void			ft_draw(void *mlx, void *win, t_point **map_to_display, int *map_size)
{
	t_int_point p1;
	t_int_point p2;

	int	x;
	int	y;

	y = 0;
	//printf("map_size[0] = %i et map_size[1] = %i \n", map_size[0], map_size[1]);
	while (y < map_size[1])
	{
		x = 0;
		while (x < map_size[0])
		{
			p1.x = (int)map_to_display[y][x].x;
			p1.y = (int)map_to_display[y][x].y;
			if (y != 0)
			{
				//printf("Y draw_line entre %d;%d et %d;%d\n", map_to_display[y][x].x, map_to_display[y][x].y, map_to_display[y - 1][x].x, map_to_display[y - 1][x].y);
				p2.x = (int)map_to_display[y - 1][x].x;
				p2.y = (int)map_to_display[y - 1][x].y;
				draw_line(mlx, win, p1, p2);
			}
			if (x != 0)
			{
				//printf("X draw_line entre %d;%d et %d;%d\n", map_to_display[y][x].x, map_to_display[y][x].y, map_to_display[y][x - 1].x, map_to_display[y][x - 1].y);
				p2.x = (int)map_to_display[y][x - 1].x;
				p2.y = (int)map_to_display[y][x - 1].y;
				draw_line(mlx, win, p1, p2);
			}
			x++;
		}
		y++;
	}
}
*/

void			ft_draw(void *mlx, void *win, t_point **map_to_display, int *map_size)
{
	t_int_point p1;
	t_int_point p2;

	int	x;
	int	y;

	y = 0;
	//printf("map_size[0] = %i et map_size[1] = %i \n", map_size[0], map_size[1]);
	while (y < map_size[1])
	{
		x = 0;
		while (x < map_size[0])
		{
			p1.x = (int)round(map_to_display[y][x].x);
			p1.y = (int)round(map_to_display[y][x].y);
			if (y != 0)
			{
				//printf("Y draw_line entre %d;%d et %d;%d\n", map_to_display[y][x].x, map_to_display[y][x].y, map_to_display[y - 1][x].x, map_to_display[y - 1][x].y);
				p2.x = (int)round(map_to_display[y - 1][x].x);
				p2.y = (int)round(map_to_display[y - 1][x].y);
				draw_line(mlx, win, p1, p2);
			}
			if (x != 0)
			{
				//printf("X draw_line entre %d;%d et %d;%d\n", map_to_display[y][x].x, map_to_display[y][x].y, map_to_display[y][x - 1].x, map_to_display[y][x - 1].y);
				p2.x = (int)round(map_to_display[y][x - 1].x);
				p2.y = (int)round(map_to_display[y][x - 1].y);
				draw_line(mlx, win, p1, p2);
			}
			x++;
		}
		y++;
	}
}





































