/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:05:24 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 16:36:38 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*dest;
	unsigned	int	index;
	unsigned	int	j;

	index = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(*dest) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[index] != '\0')
	{
		dest[index] = s1[index];
		index++;
	}
	while (s2[j] != '\0')
	{
		dest[index] = s2[j];
		index++;
		j++;
	}
	dest[index] = '\0';
	return (dest);
}
