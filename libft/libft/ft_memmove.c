/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:33:13 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 17:23:52 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*ret;
	char			*nwsrc;
	unsigned	int	i;

	i = 0;
	ret = (char*)dst;
	nwsrc = (char*)src;
	if (dst < src)
	{
		while (++i < len + 1)
			ret[i - 1] = nwsrc[i - 1];
	}
	else
	{
		while (len-- > 0)
			ret[len] = nwsrc[len];
	}
	return (ret);
}
