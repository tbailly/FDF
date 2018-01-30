/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/30 18:02:56 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include "libft/libft.h"

typedef struct		s_point
{
	float	x;
	float	y;
	float	z;
}					t_point;

typedef struct		s_int_point
{
	int				x;
	int				y;
	unsigned	int	color;
}					t_int_point;

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

int					**ft_get_height_map(char *filename, int **map_size_pt);
int					ft_rotate_map(int keycode, void *param);

void				ft_draw(char *img_str, t_point **map_to_display, int *map_size);


void				ft_debug_print_point_array(t_point **map_to_display, int *map_size);
t_point				**ft_create_point_array(int **height_map, int *map_size);
t_point				**ft_apply_iso_matrix(t_point **map_to_display, int *map_size);

void				ft_free_strarr(char **strarr);

t_point				**ft_rotate_x(t_point **map_to_display, int *map_size, float angle);
t_point				**ft_rotate_y(t_point **map_to_display, int *map_size, float angle);
t_point				**ft_rotate_z(t_point **map_to_display, int *map_size, float angle);


t_point				**ft_resize(t_point **map_to_display, int *map_size);



#endif