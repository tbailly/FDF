/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <tbailly-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:04:55 by tbailly-          #+#    #+#             */
/*   Updated: 2018/02/05 11:05:20 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_intarr(int **arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_ptrarr(t_point **arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_free_strarr(char **strarr)
{
	int	i;

	i = 0;
	while (strarr[i] != NULL)
	{
		free(strarr[i]);
		i++;
	}
	free(strarr[i]);
	free(strarr);
}
