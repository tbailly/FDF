/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:21:11 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/25 00:07:33 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrepchr(char *s, char c1, char c2)
{
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (c1 == '\0' || c2 == '\0')
		return ((char*)s);
	while (s[i] != '\0')
	{
		if (s[i] == c1)
			s[i] = c2;
		i++;
	}
	return (s);
}
