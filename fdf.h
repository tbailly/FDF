/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 13:27:51 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include "libft/includes/get_next_line.h"
#include "libft/includes/libft.h"

typedef struct		s_point
{
	float	x;
	float	y;
	float	z;
	unsigned	int	color;
}					t_point;

typedef struct		s_int_point
{
	int				x;
	int				y;
	unsigned	int	color;
}					t_int_point;

typedef struct		s_bounds
{
	float	minx;
	float	miny;
	float	maxx;
	float	maxy;
}					t_bounds;

typedef struct		s_bresenheim
{
	int	a;
	int	b;
	int	p;
	int	x_greater_y;
}					t_bresenheim;

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

int					**ft_get_height_map(char *filename, int **map_size_pt);

void				ft_draw_image(char *img_str, t_point **map_to_display, int *map_size);
void				ft_draw_line(char *img_str, t_int_point p1, t_int_point p2);

t_point				**ft_create_point_array(int **height_map, int *map_size);
t_point				**ft_apply_iso_matrix(t_point **map_to_display, int *map_size);

void				ft_free_strarr(char **strarr);

t_point				**ft_rotate_x(t_point **map_to_display, int *map_size, float angle);
t_point				**ft_rotate_y(t_point **map_to_display, int *map_size, float angle);
t_point				**ft_rotate_z(t_point **map_to_display, int *map_size, float angle);


t_point				**ft_resize(t_point **map_to_display, int *map_size);

int					*ft_color_datas(void);
int					*ft_convert_color(unsigned int color);
int					ft_calculate_color(t_int_point p1, t_int_point p2, t_int_point p3, int x_longer_than_y);

void				ft_exit(char *s);

#endif