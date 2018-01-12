/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:42:17 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/17 13:21:54 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char *str)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			ft_putchar(*str);
			str++;
		}
	}
	ft_putchar('\n');
}
