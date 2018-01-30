/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:37:35 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/25 01:38:06 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*ft_int_len(int value, int *lenptr)
{
	int		count;
	char	*str;

	count = 1;
	if (value < 0)
		count++;
	while (value / 10 != 0)
	{
		value = value / 10;
		count++;
	}
	*lenptr = count;
	str = (char*)malloc(sizeof(*str) * (count + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

char			*ft_itoa(int value)
{
	char	*ret;
	int		len;

	ret = ft_int_len(value, &len);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (value / 10 != 0)
	{
		ret[len - 1] = ft_abs(value % 10) + 48;
		len--;
		value = value / 10;
	}
	ret[len - 1] = ft_abs(value % 10) + 48;
	if (value < 0)
		ret[0] = '-';
	return (ret);
}
