/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:26 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 17:22:44 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keyboard_input(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_error_handler(int ac)
{
	if (ac != 2)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_mlx_components	mlx_c;
	int					**height_map;
	t_point				**map_to_display;
	int					*map_size;

	ft_error_handler(ac);
	height_map = ft_get_height_map(av[1], &map_size);
	map_to_display = ft_create_point_array(height_map, map_size);
	map_to_display = ft_apply_iso_matrix(map_to_display, map_size);
	mlx_c.mlx = mlx_init();
	mlx_c.win = mlx_new_window(mlx_c.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	ft_draw_image(&(mlx_c), map_to_display, map_size);
	mlx_put_image_to_window(mlx_c.mlx, mlx_c.win, mlx_c.img, 0, 0);
	mlx_key_hook(mlx_c.win, keyboard_input, 0);
	mlx_loop(mlx_c.mlx);
	ft_free_intarr(height_map);
	ft_free_ptrarr(map_to_display);
	return (0);
}
