/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:39:35 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/20 11:54:58 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_determine_negative(char *str, int *negptr)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		*negptr = (str[i] == '-') ? 1 : 0;
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	long	res;
	long	tmpres;
	int		i;
	int		isnegative;

	res = 0;
	tmpres = -1;
	i = ft_determine_negative((char *)str, &isnegative);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + ((long)str[i] - 48);
		if (tmpres > res)
			return ((isnegative == 1) ? 0 : -1);
		tmpres = res;
		i++;
	}
	if (isnegative == 1)
		res = -res;
	return (res);
}
