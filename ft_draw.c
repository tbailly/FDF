/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:42:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/30 19:28:33 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void				ft_debug_print_point_array(t_point **map_to_display, int *map_size)
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

static int	*ft_convert_color(unsigned int color)
{
	int	i;
	int	*res;

	i = 0;
	res = (int*)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		res[i] = color % 256;
		color = color / 256;
		i++;
	}
	return (res);
}

static	void		ft_draw_pixel(char *img_str, t_int_point p)
{
	int pixel_i;
	int	*colors;

	if (p.x < WIN_WIDTH && p.y < WIN_HEIGHT)
	{
		colors = ft_convert_color(p.color);
		pixel_i = (p.y * WIN_WIDTH * 4) + (p.x * 4);
		img_str[pixel_i]		= colors[0]; //B
		img_str[pixel_i + 1]	= colors[1]; //V
		img_str[pixel_i + 2]	= colors[2]; //R
		img_str[pixel_i + 3]	= colors[3]; //A ?
	}
}

int	ft_calculate_color(t_int_point p1, t_int_point p2, t_int_point p3, int x_longer_than_y)
{
	float ratio;
	int *colors_p1;
	int *colors_p2;
	int *res;

	colors_p1 = ft_convert_color(p1.color);
	colors_p2 = ft_convert_color(p2.color);
	res = (int*)malloc(sizeof(int) * 4);
	if (x_longer_than_y == 1)
		ratio = fabs((float)(p3.x - p1.x) / (float)(p2.x - p1.x));
	else
		ratio = fabs((float)(p3.y - p1.y) / (float)(p2.y - p1.y));
	if (ratio > 1)
		ratio = 1 / ratio;
	ratio *= 100;

	if (colors_p1[0] > colors_p2[0])
		res[0] = colors_p1[0] - (ft_subs_max(colors_p2[0], colors_p1[0]) * ratio / 100);
	else
		res[0] = ft_subs_max(colors_p2[0], colors_p1[0]) * ratio / 100 + colors_p1[0];
	if (colors_p1[1] > colors_p2[1])
		res[1] = colors_p1[1] - (ft_subs_max(colors_p2[1], colors_p1[1]) * ratio / 100);
	else
		res[1] = ft_subs_max(colors_p2[1], colors_p1[1]) * ratio / 100 + colors_p1[1];
	if (colors_p1[2] > colors_p2[2])
		res[2] = colors_p1[2] - (ft_subs_max(colors_p2[2], colors_p1[2]) * ratio / 100);
	else
		res[2] = ft_subs_max(colors_p2[2], colors_p1[2]) * ratio / 100 + colors_p1[2];
	if (colors_p1[3] > colors_p2[3])
		res[3] = colors_p1[3] - (ft_subs_max(colors_p2[3], colors_p1[3]) * ratio / 100);
	else
		res[3] = ft_subs_max(colors_p2[3], colors_p1[3]) * ratio / 100 + colors_p1[3];

	p3.color = 1 * res[0] + 256 * res[1] + 65536 * res[2] + 16777216 * res[3];

	printf("p1 color : %u;%u;%u;%u et p2 color : %u;%u;%u;%u et p3 color : %u;%u;%u;%u \n", colors_p1[0], colors_p1[1],
			colors_p1[2], colors_p1[3], colors_p2[0], colors_p2[1], colors_p2[2], colors_p2[3], res[0],
			res[1], res[2], res[3]);
	return (p3.color);
}

static	void		ft_draw_line(char *img_str, t_int_point p1, t_int_point p2)
{
	int	a;
	int	b;
	int	p;
	int x_longer_than_y;
	t_int_point	direction;
	t_int_point ptemp;

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
		//ptemp.color = ft_calculate_color(p1, p2, ptemp, x_longer_than_y);
		ptemp.color = 0xFFFFFF;
		ft_draw_pixel(img_str, ptemp);
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
}

void				ft_draw(char *img_str, t_point **map_to_display, int *map_size)
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
				//printf("Y ft_draw_line entre %d;%d et %d;%d\n", map_to_display[y][x].x, map_to_display[y][x].y, map_to_display[y - 1][x].x, map_to_display[y - 1][x].y);
				p2.x = (int)round(map_to_display[y - 1][x].x);
				p2.y = (int)round(map_to_display[y - 1][x].y);
				ft_draw_line(img_str, p1, p2);
			}
			if (x != 0)
			{
				//printf("X ft_draw_line entre %d;%d et %d;%d\n", map_to_display[y][x].x, map_to_display[y][x].y, map_to_display[y][x - 1].x, map_to_display[y][x - 1].y);
				p2.x = (int)round(map_to_display[y][x - 1].x);
				p2.y = (int)round(map_to_display[y][x - 1].y);
				ft_draw_line(img_str, p1, p2);
			}
			x++;
		}
		y++;
	}
}







































