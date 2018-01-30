/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:52:06 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/25 01:28:28 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char			*str2;
	unsigned	int	index;
	unsigned	int	j;

	str2 = (char*)s2;
	index = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0')
	{
		s1[index] = s2[j];
		index++;
		j++;
	}
	s1[index] = '\0';
	return (s1);
}
