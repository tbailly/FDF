/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:20:14 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 15:52:50 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*tmpsrc;
	char			*ret;
	unsigned	int	i;

	i = 0;
	tmpsrc = (char*)src;
	ret = (char*)dst;
	while (++i < n + 1)
		ret[i - 1] = tmpsrc[i - 1];
	return (ret);
}
