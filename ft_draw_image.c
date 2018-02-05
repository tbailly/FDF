/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:27:04 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 10:33:48 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char			*ft_get_image(t_info *mlx_pt)
{
	int		bpp;
	int		size_line;
	int		endian;
	char	*img_str;

	bpp = 4;
	size_line = WIN_WIDTH;
	endian = 0;
	(*mlx_pt).img = mlx_new_image((*mlx_pt).mlx, WIN_WIDTH, WIN_HEIGHT);
	img_str = mlx_get_data_addr((*mlx_pt).img, &bpp, &size_line, &endian);
	return (img_str);
}

static t_i_point	ft_get_p1(t_i_point p1, t_point **map, int x, int y)
{
	p1.x = (int)round(map[y][x].x);
	p1.y = (int)round(map[y][x].y);
	p1.color = map[y][x].color;
	return (p1);
}

static t_i_point	ft_get_p2_y(t_i_point p2, t_point **map, int x, int y)
{
	if (y != 0)
	{
		p2.x = (int)round(map[y - 1][x].x);
		p2.y = (int)round(map[y - 1][x].y);
		p2.color = map[y - 1][x].color;
	}
	else
	{
		p2.x = -5;
		p2.y = -5;
	}
	return (p2);
}

static t_i_point	ft_get_p2_x(t_i_point p2, t_point **map, int x, int y)
{
	if (x != 0)
	{
		p2.x = (int)round(map[y][x - 1].x);
		p2.y = (int)round(map[y][x - 1].y);
		p2.color = map[y][x - 1].color;
	}
	else
	{
		p2.x = -5;
		p2.y = -5;
	}
	return (p2);
}

void				ft_draw_image(t_info *mlx_pt, t_point **map, int *map_size)
{
	char		*img_str;
	t_i_point	p1;
	t_i_point	p2;
	int			x;
	int			y;

	img_str = ft_get_image(mlx_pt);
	y = 0;
	while (y < map_size[1])
	{
		x = 0;
		while (x < map_size[0])
		{
			p1 = ft_get_p1(p1, map, x, y);
			p2 = ft_get_p2_x(p2, map, x, y);
			if (p2.x != -5)
				ft_draw_line(img_str, p1, p2);
			p2 = ft_get_p2_y(p2, map, x, y);
			if (p2.x != -5)
				ft_draw_line(img_str, p1, p2);
			x++;
		}
		y++;
	}
}
