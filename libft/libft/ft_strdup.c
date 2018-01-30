/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:24:37 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/29 18:45:59 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*ret;

	i = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (!(ret = (char*)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	while (++i < len + 1)
		ret[i - 1] = str[i - 1];
	ret[i - 1] = '\0';
	return (ret);
}
