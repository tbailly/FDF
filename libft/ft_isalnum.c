/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:15:12 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/20 10:41:04 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int n)
{
	if ((n >= '0' && n <= '9') ||
		(n >= 'A' && n <= 'Z') ||
		(n >= 'a' && n <= 'z'))
		return (1);
	else
		return (0);
}
