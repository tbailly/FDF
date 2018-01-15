/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/15 23:11:04 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include "libft/libft.h"

typedef struct		s_point
{
	int	x;
	int	y;
}					t_point;

typedef struct		s_point3d
{
	int	x;
	int	y;
	int	z;
}					t_point3d;

int					**ft_get_height_map(char *filename, int **map_size_pt);
int					ft_rotate_map(int keycode, void *param);
void				ft_draw(void *mlx, void *win, t_point **height_map, int *map_size);
void				draw_line(void *mlx, void *win, t_point p1, t_point p2);
t_point				**ft_apply_iso_matrix(int **height_map, int*map_size);

void				ft_free_strarr(char **strarr);

#endif