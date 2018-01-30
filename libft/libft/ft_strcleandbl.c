/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcleandbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:57:50 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/18 20:58:13 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	char	*ft_malloccleandbl(const char *s, char c, int *f, int *l)
{
	int		i;
	int		count;
	char	*ret;

	i = ft_strlen(s) - 1;
	count = 0;
	while (s[i] == c)
		i--;
	*l = i;
	i = 0;
	while (s[i] == c)
		i++;
	*f = i;
	if (*l >= *f)
	{
		while (i < *l && s[i] != '\0')
		{
			if ((s[i] == c && s[i + 1] != c) || s[i] != c)
				count++;
			i++;
		}
		if ((ret = (char*)malloc(sizeof(*ret) * (count + 2))))
			return (ret);
	}
	return (NULL);
}

char			*ft_strcleandbl(const char *s, char c)
{
	int		i;
	int		j;
	int		first;
	int		last;
	char	*ret;

	if (s == NULL)
		return (NULL);
	ret = ft_malloccleandbl(s, c, &first, &last);
	if (ret == NULL)
		return (NULL);
	if (ft_strcmp(s, ret) == 0)
		return (ret);
	i = 0;
	j = first - 1;
	while (++j <= last)
	{
		if ((s[j] == c && s[j + 1] != c) || s[j] != c)
		{
			ret[i] = s[j];
			i++;
		}
	}
	ret[i] = '\0';
	return (ret);
}
