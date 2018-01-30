/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:30:27 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/20 13:37:31 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_cmp(unsigned int i, const char *hs, const char *ndl, size_t len)
{
	int		j;

	j = 0;
	while (hs[i] == ndl[j] && hs[i] != '\0' && ndl[j] != '\0' && i < len)
	{
		i++;
		j++;
	}
	if (ndl[j] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strnstr(const char *hst, const char *ndl, size_t len)
{
	unsigned	int		i;

	i = 0;
	if (*ndl == '\0')
		return ((char*)hst);
	while (hst[i] != '\0' && i < len)
	{
		if (hst[i] == ndl[0] && ft_cmp(i, hst, ndl, len) == 1)
			return ((char*)&hst[i]);
		i++;
	}
	return (NULL);
}
