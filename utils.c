/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 21:26:39 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 11:05:26 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*ft_convert_color(unsigned int color)
{
	int	i;
	int	*res;

	i = 0;
	res = (int*)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		res[i] = color % 256;
		color = color / 256;
		i++;
	}
	return (res);
}

void	ft_exit(char *s)
{
	perror(s);
	ft_putstr_fd("Exiting.\n", 2);
	exit(0);
}

void	ft_exit_message(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putstr_fd(" Exiting.\n", 2);
	exit(0);
}
