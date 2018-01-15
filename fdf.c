/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:26 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/15 23:50:56 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		**height_map;
	t_point **map_to_display;
	int		*map_size;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 2000, 2000, "tbailly- fdf");
	

	height_map = ft_get_height_map(argv[1], &map_size);
	map_to_display = ft_apply_iso_matrix(height_map, map_size);
	//printf("Map to display : %i;%i\n", map_to_display[1][1].x, map_to_display[1][1].y);
	ft_draw(mlx, win, map_to_display, map_size);
	//mlx_key_hook(win, keyboard_input, 0);





	mlx_loop(mlx);


	return (0);
}
