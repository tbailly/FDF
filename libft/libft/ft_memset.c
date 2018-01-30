/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 20:57:12 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/20 09:52:43 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned	char	*str;
	unsigned	int		i;

	str = (unsigned char*)s;
	i = 0;
	while (++i < (unsigned int)(len + 1))
		str[i - 1] = (unsigned char)c;
	return (str);
}
