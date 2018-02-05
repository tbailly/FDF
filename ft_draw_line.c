/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:42:17 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 10:37:36 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_i_point		get_direction(t_i_point p1, t_i_point p2)
{
	int			sub;
	int			sub_abs;
	t_i_point	res;

	sub = p2.x - p1.x;
	sub_abs = ft_abs(sub);
	res.x = (sub == 0) ? 0 : (sub / sub_abs);
	sub = p2.y - p1.y;
	sub_abs = ft_abs(sub);
	res.y = (sub == 0) ? 0 : (sub / sub_abs);
	return (res);
}

static	t_bresenheim	ft_get_bresenheim_val(t_i_point p1, t_i_point p2)
{
	t_bresenheim bres;

	if (ft_abs(p1.x - p2.x) > ft_abs(p1.y - p2.y))
	{
		bres.a = 2 * (ft_abs(p1.y - p2.y));
		bres.b = bres.a - (2 * (ft_abs(p1.x - p2.x)));
		bres.p = bres.a - ft_abs(p1.x - p2.x);
		bres.x_greater_y = 1;
	}
	else
	{
		bres.a = 2 * (ft_abs(p1.x - p2.x));
		bres.b = bres.a - (2 * (ft_abs(p1.y - p2.y)));
		bres.p = bres.a - ft_abs(p1.y - p2.y);
		bres.x_greater_y = 0;
	}
	return (bres);
}

static	void			ft_draw_pixel(char *img_str, t_i_point p)
{
	int pixel_i;
	int	*colors;

	if (p.x < WIN_WIDTH && p.y < WIN_HEIGHT)
	{
		colors = ft_convert_color(p.color);
		pixel_i = (p.y * WIN_WIDTH * 4) + (p.x * 4);
		img_str[pixel_i] = colors[0];
		img_str[pixel_i + 1] = colors[1];
		img_str[pixel_i + 2] = colors[2];
		img_str[pixel_i + 3] = colors[3];
		free(colors);
	}
}

static t_i_point		ft_i_point_cpy(t_i_point src)
{
	t_i_point	dst;

	dst.x = src.x;
	dst.y = src.y;
	return (dst);
}

void					ft_draw_line(char *img_str, t_i_point p1, t_i_point p2)
{
	t_bresenheim	bres;
	t_i_point		direction;
	t_i_point		ptemp;

	bres = ft_get_bresenheim_val(p1, p2);
	direction = get_direction(p1, p2);
	ptemp = ft_i_point_cpy(p1);
	while (ptemp.x != p2.x || ptemp.y != p2.y)
	{
		ptemp.color = ft_calc_color(p1, p2, ptemp, bres.x_greater_y);
		ft_draw_pixel(img_str, ptemp);
		if (bres.x_greater_y)
		{
			ptemp.x += 1 * direction.x;
			if (bres.p >= 0)
				ptemp.y += 1 * direction.y;
		}
		else
		{
			ptemp.y += 1 * direction.y;
			if (bres.p >= 0)
				ptemp.x += 1 * direction.x;
		}
		bres.p = (bres.p >= 0) ? (bres.p + bres.b) : (bres.p + bres.a);
	}
}
