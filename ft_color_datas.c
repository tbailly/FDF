/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_datas.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 21:27:21 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/01 17:25:52 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*ft_color_datas(void)
{
	int *res;

	if (!(res = (int*)malloc(sizeof(int) * 13)))
		exit(0);
	res[0] = 0x78BFE9;
	res[1] = 0xBADDF6;
	res[2] = 0xB0D371;
	res[3] = 0xB0D371;
	res[4] = 0x81C158;
	res[5] = 0x81C158;
	res[6] = 0xFEE9AD;
	res[7] = 0xFED895;
	res[8] = 0xF0BC88;
	res[9] = 0xF0BC88;
	res[10] = 0x5E440F;
	res[11] = 0xFFFFFF;
	res[12] = 0xFFFFFF;
	return (res);
}
