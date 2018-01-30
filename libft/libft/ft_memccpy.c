/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:02:28 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 15:53:26 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned	char	*tmpsrc;
	unsigned	char	*res;
	unsigned	int		i;

	i = 0;
	tmpsrc = (unsigned char*)src;
	res = (unsigned char*)dst;
	while (i < n)
	{
		res[i] = tmpsrc[i];
		if (tmpsrc[i] == (unsigned char)c)
			return (&res[i + 1]);
		i++;
	}
	return (NULL);
}
