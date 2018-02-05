/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 10:47:52 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	unsigned	int	color;
}					t_point;

typedef struct		s_i_point
{
	int				x;
	int				y;
	unsigned	int	color;
}					t_i_point;

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

typedef struct		s_info
{
	void	*mlx;
	void	*win;
	void	*img;
}					t_info;

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

int					**ft_get_h_map(char *filename, int **map_size_pt);

void				ft_draw_image(t_info *mlx_pt, t_point **map, int *map_size);
void				ft_draw_line(char *img_str, t_i_point p1, t_i_point p2);

t_point				**ft_create_point_array(int **h_map, int *map_size);
t_point				**ft_apply_iso_matrix(t_point **map, int *map_size);

t_point				**ft_rotate_x(t_point **map, int *map_size, float angle);
t_point				**ft_rotate_y(t_point **map, int *map_size, float angle);
t_point				**ft_rotate_z(t_point **map, int *map_size, float angle);

t_point				**ft_resize(t_point **map, int *map_size);

int					*ft_color_datas(void);
int					*ft_convert_color(unsigned int color);
int					ft_calc_color(t_i_point p1, t_i_point p2,
					t_i_point p3, int x_sup_y);

void				ft_free_intarr(int **arr, int length);
void				ft_free_ptrarr(t_point **arr, int length);
void				ft_free_strarr(char **strarr);
void				ft_exit(char *s);
void				ft_exit_message(char *s);

#endif
