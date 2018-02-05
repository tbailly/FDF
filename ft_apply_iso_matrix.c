/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_iso_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:15:45 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 09:59:58 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	**ft_apply_iso_matrix(t_point **map_to_display, int *map_size)
{
	map_to_display = ft_rotate_z(map_to_display, map_size, 45);
	map_to_display = ft_rotate_x(map_to_display, map_size, 45);
	map_to_display = ft_resize(map_to_display, map_size);
	return (map_to_display);
}
