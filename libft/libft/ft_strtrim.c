/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:15:19 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/20 11:07:45 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	ft_trimcount(char const *s, size_t *start)
{
	size_t			count;
	unsigned	int	i;

	count = 0;
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	*start = i;
	if (s[i] == '\0')
		return (0);
	i = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i--;
	count = i - *start + 1;
	return (count);
}

char			*ft_strtrim(char const *s)
{
	char			*ret;
	size_t			start;
	size_t			len;
	unsigned	int	i;

	if (s == NULL)
		return (NULL);
	len = ft_trimcount(s, &start);
	if (!(ret = (char *)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
