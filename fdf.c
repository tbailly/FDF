/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:26 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 12:00:49 by tbailly-         ###   ########.fr       */
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
		ft_putstr("Usage : ./fdf <filename> [ case_size z_size ]\n");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_info	mlx_c;
	int		**h_map;
	t_point	**map_to_display;
	int		*map_size;

	if (!(map_size = (int*)malloc(sizeof(int*) * 2)))
		ft_exit("main");
	map_size[0] = 0;
	map_size[1] = 0;
	ft_error_handler(ac);
	h_map = ft_get_h_map(av[1], &map_size);
	map_to_display = ft_create_point_array(h_map, map_size);
	map_to_display = ft_apply_iso_matrix(map_to_display, map_size);
	mlx_c.mlx = mlx_init();
	mlx_c.win = mlx_new_window(mlx_c.mlx, WIN_WIDTH, WIN_HEIGHT, "fdf");
	ft_draw_image(&(mlx_c), map_to_display, map_size);
	mlx_put_image_to_window(mlx_c.mlx, mlx_c.win, mlx_c.img, 0, 0);
	mlx_key_hook(mlx_c.win, keyboard_input, 0);
	ft_free_intarr(h_map, map_size[1]);
	ft_free_ptrarr(map_to_display, map_size[1]);
	free(map_size);
	mlx_destroy_image(mlx_c.mlx, mlx_c.img);
	mlx_loop(mlx_c.mlx);
	return (0);
}
