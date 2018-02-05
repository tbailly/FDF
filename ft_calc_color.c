/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 20:55:19 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 09:57:50 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	*ft_find_ratio_color(int *colors, int *c_p1, int *c_p2, float ratio)
{
	if (c_p1[0] > c_p2[0])
		colors[0] = c_p1[0] - (c_p1[0] - c_p2[0]) * ratio / 100;
	else
		colors[0] = c_p1[0] + (c_p2[0] - c_p1[0]) * ratio / 100;
	if (c_p1[1] > c_p2[1])
		colors[1] = c_p1[1] - (c_p1[1] - c_p2[1]) * ratio / 100;
	else
		colors[1] = c_p1[1] + (c_p2[1] - c_p1[1]) * ratio / 100;
	if (c_p1[2] > c_p2[2])
		colors[2] = c_p1[2] - (c_p1[2] - c_p2[2]) * ratio / 100;
	else
		colors[2] = c_p1[2] + (c_p2[2] - c_p1[2]) * ratio / 100;
	if (c_p1[3] > c_p2[3])
		colors[3] = c_p1[3] - (c_p1[3] - c_p2[3]) * ratio / 100;
	else
		colors[3] = c_p1[3] + (c_p2[3] - c_p1[3]) * ratio / 100;
	return (colors);
}

int			ft_calc_color(t_i_point p1, t_i_point p2, t_i_point p3, int x_sup_y)
{
	float	ratio;
	int		*res;
	int		*c_p1;
	int		*c_p2;

	c_p1 = ft_convert_color(p1.color);
	c_p2 = ft_convert_color(p2.color);
	if (!(res = (int*)malloc(sizeof(int) * 4)))
		exit(0);
	if (x_sup_y == 1)
		ratio = fabs((float)(p3.x - p1.x) / (float)(p2.x - p1.x));
	else
		ratio = fabs((float)(p3.y - p1.y) / (float)(p2.y - p1.y));
	if (ratio > 1)
		ratio = 1 / ratio;
	ratio *= 100;
	res = ft_find_ratio_color(res, c_p1, c_p2, ratio);
	p3.color = 1 * res[0] + 256 * res[1] + 65536 * res[2] + 16777216 * res[3];
	free(res);
	free(c_p1);
	free(c_p2);
	return (p3.color);
}
