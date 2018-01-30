/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:24:54 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 16:28:18 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	if (s == NULL)
		return (NULL);
	if (!(ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s) + 1))))
		return (NULL);
	i = -1;
	while (s[++i] != '\0' && s != NULL)
		ret[i] = f(s[i]);
	ret[i] = '\0';
	return (ret);
}
