/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 01:00:51 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/25 01:22:03 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*ft_int_len_base(int value, int base, int *lenptr)
{
	int		count;
	char	*str;

	count = 1;
	if (value < 0 && base == 10)
		count++;
	while (value / base != 0)
	{
		value = value / base;
		count++;
	}
	*lenptr = count;
	str = (char*)malloc(sizeof(*str) * (count + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

char			*ft_itoa_base(int value, int base)
{
	char	*indx;
	char	*ret;
	int		len;

	if (base < 2 || base > 16)
		return (NULL);
	indx = "0123456789ABCDEF";
	ret = ft_int_len_base(value, base, &len);
	if (ret == NULL)
		return (NULL);
	ret[len] = '\0';
	while (value / base != 0)
	{
		ret[len - 1] = indx[ft_abs(value % base)];
		len--;
		value = value / base;
	}
	ret[len - 1] = indx[ft_abs(value % base)];
	if (value < 0 && base == 10)
		ret[0] = '-';
	return (ret);
}
