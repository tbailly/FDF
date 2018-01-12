/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:42:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/12 11:43:48 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

static	t_point	get_direction(t_point p1, t_point p2)
{
	int sub;
	int sub_abs;
	t_point	res;
	
	sub = p2.x - p1.x;
	sub_abs = ft_abs(sub);
	res.x = sub / sub_abs;
	
	sub = p2.y - p1.y;
	sub_abs = ft_abs(sub);
	res.y = sub / sub_abs;
	return (res);
}

void			draw_line(void *mlx, void *win, t_point p1, t_point p2)
{
	int	a;
	int	b;
	int	p;
	int x_longer_than_y;
	int i;
	t_point	direction;

	i = 0;
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

	while ((p1.x != p2.x || p1.y != p2.y) && i < 700)
	{
		mlx_pixel_put(mlx, win, p1.x, p1.y, 0x00FFFFFF);
		i++;
		if (x_longer_than_y)
		{
			p1.x += 1 * direction.x;
			if ((p >= 0))
				p1.y += 1 * direction.y;
		}
		else
		{
			p1.y += 1 * direction.y;
			if ((p >= 0))
				p1.x += 1 * direction.x;
		}
		p = (p >= 0) ? (p + b) :(p + a);
	}

	printf("draw_line %p, %p, p1: %d;%d et p2: %d;%d\n", mlx, win, p1.x, p1.y, p2.x, p2.y);
}