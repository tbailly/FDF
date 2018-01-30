/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:49:11 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 19:14:46 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*ret;

	if (!(ret = (char*)malloc(sizeof(*ret) * size)))
		return (NULL);
	ret = ft_memset(ret, 0, size);
	return (ret);
}
