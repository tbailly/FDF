/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 13:27:04 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 17:27:33 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	char	*ft_get_image(t_mlx_components *mlx_pt)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*img_str;

	bits_per_pixel = 4;
	size_line = WIN_WIDTH;
	endian = 0;
	(*mlx_pt).img = mlx_new_image((*mlx_pt).mlx, WIN_WIDTH, WIN_HEIGHT);
	img_str = mlx_get_data_addr((*mlx_pt).img, &bits_per_pixel, &size_line, &endian);
	return (img_str);
}

void			ft_draw_image(t_mlx_components *mlx_pt, t_point **map_to_display, int *map_size)
{
	char		*img_str;
	t_int_point	p1;
	t_int_point	p2;
	int			x;
	int			y;

	img_str = ft_get_image(mlx_pt);
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
