/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 11:44:39 by tbailly-          #+#    #+#             */
/*   Updated: 2018/01/12 11:45:32 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int ft_rotate_map(int keycode, void *param)
{
	printf("ft_rotate_map --> keycode : %d and ptr %p\n", keycode, param);
	return (keycode);
}