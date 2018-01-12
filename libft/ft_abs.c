/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:16:18 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/25 01:36:15 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned	int	ft_abs(int a)
{
	unsigned	int	ret;

	if (a < 0)
		ret = (unsigned int)a * -1;
	else
		ret = (unsigned int)a;
	return (ret);
}
