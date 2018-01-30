/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:49:15 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/17 23:45:20 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_split_count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	char	*ft_split_word_len(const char *s, char c, int i)
{
	int		count;
	int		j;
	char	*ret;

	count = 1;
	j = i;
	while (s[i] != c && (s[i + 1] != c && s[i + 1] != '\0'))
	{
		count++;
		i++;
	}
	i = j;
	j = 0;
	if (!(ret = (char*)malloc(sizeof(*ret) * (count + 1))))
		return (NULL);
	count += i;
	while (i < count)
	{
		ret[j] = s[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned	int	i;
	unsigned	int	j;
	unsigned	int	words;
	char			**ret;

	i = 0;
	j = 0;
	ret = NULL;
	if (s == NULL)
		return (NULL);
	words = ft_split_count_words((char*)s, c);
	if (!(ret = (char**)malloc(sizeof(*ret) * (words + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c && s[i] != '\0') ||
			(s[i] != c && (s[i - 1] == c || s[i - 1] == '\0')))
		{
			ret[j] = ft_split_word_len(s, c, i);
			j++;
		}
		i++;
	}
	ret[j] = 0;
	return (ret);
}
