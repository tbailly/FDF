/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:27:04 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 13:37:31 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_draw_image(char *img_str, t_point **map_to_display, int *map_size)
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