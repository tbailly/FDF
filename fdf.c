/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:26 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/30 16:07:26 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"

char	*ft_get_image(void *img_ptr)
{
	int	bits_per_pixel;
	int	size_line;
	int	endian;
	char	*img_str;

	bits_per_pixel = 4;
	size_line = WIN_WIDTH;
	endian = 0;
	img_str = mlx_get_data_addr(img_ptr, &bits_per_pixel, &size_line, &endian);
	return (img_str);
}


int keyboard_input(int keycode, void *param)
{
	if (keycode == 53)
	{
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_str;
	int		**height_map;
	t_point **map_to_display;
	int		*map_size;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "tbailly- fdf");
	img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img_str = ft_get_image(img);



	height_map = ft_get_height_map(argv[1], &map_size);
	map_to_display = ft_create_point_array(height_map, map_size);
	map_to_display = ft_apply_iso_matrix(map_to_display, map_size);
	ft_draw(img_str, map_to_display, map_size);



	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_key_hook(win, keyboard_input, 0);
	mlx_loop(mlx);


	return (0);
}
