/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:10:26 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/12 15:11:29 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		**height_map;
	int		map_h;

	row_len = 0;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "tbailly- fdf");
	

	height_map = ft_get_height_map(argv[1]);

	
	//mlx_key_hook(win, keyboard_input, 0);





	mlx_loop(mlx);


	return (0);
}
