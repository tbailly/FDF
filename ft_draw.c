/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:42:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/30 23:28:55 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

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

static	void		ft_draw_pixel(char *img_str, t_int_point p)
{
	int pixel_i;
	int	*colors;

	if (p.x < WIN_WIDTH && p.y < WIN_HEIGHT)
	{
		colors = ft_convert_color(p.color);
		pixel_i = (p.y * WIN_WIDTH * 4) + (p.x * 4);
		img_str[pixel_i]		= colors[0];
		img_str[pixel_i + 1]	= colors[1];
		img_str[pixel_i + 2]	= colors[2];
		img_str[pixel_i + 3]	= colors[3];
	}
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
		ptemp.color = ft_calculate_color(p1, p2, ptemp, x_longer_than_y);
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
	while (y < map_size[1])
	{
		x = 0;
		while (x < map_size[0])
		{
			p1.x = (int)round(map_to_display[y][x].x);
			p1.y = (int)round(map_to_display[y][x].y);
			p1.color = map_to_display[y][x].color;
			if (y != 0)
			{
				p2.x = (int)round(map_to_display[y - 1][x].x);
				p2.y = (int)round(map_to_display[y - 1][x].y);
				p2.color = map_to_display[y - 1][x].color;
				ft_draw_line(img_str, p1, p2);
			}
			if (x != 0)
			{
				p2.x = (int)round(map_to_display[y][x - 1].x);
				p2.y = (int)round(map_to_display[y][x - 1].y);
				p2.color = map_to_display[y][x - 1].color;
				ft_draw_line(img_str, p1, p2);
			}
			x++;
		}
		y++;
	}
}







































