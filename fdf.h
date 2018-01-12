/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:05:14 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/12 15:16:31 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <math.h>
#include "libft/libft.h"

typedef struct		s_point
{
	unsigned	int	x;
	unsigned	int	y;
	unsigned	int	z;
}					t_point;

int					**ft_get_height_map(char *filename);
int					ft_rotate_map(int keycode, void *param);
void				draw_line(void *mlx, void *win, t_point p1, t_point p2);

#endif