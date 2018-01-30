/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:53:33 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/20 10:25:16 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_ndlcmp(int i, const char *hstck, const char *ndl)
{
	int		j;

	j = 0;
	while (hstck[i] == ndl[j] && hstck[i] != '\0' && ndl[j] != '\0')
	{
		i++;
		j++;
	}
	if (ndl[j] == '\0')
		return (1);
	else
		return (0);
}

char		*ft_strstr(const char *hst, const char *ndl)
{
	int		i;

	i = 0;
	if (*ndl == '\0')
		return ((char*)hst);
	while (hst[i] != '\0')
	{
		if (hst[i] == ndl[0] && ft_ndlcmp(i, hst, ndl) == 1)
			return ((char*)&hst[i]);
		i++;
	}
	return (NULL);
}
