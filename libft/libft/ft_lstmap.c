/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbailly- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:40:22 by tbailly-          #+#    #+#             */
/*   Updated: 2017/11/25 00:41:26 by tbailly-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*freshlst;
	t_list	*newelem;

	if (lst == NULL)
		return (NULL);
	if (!(freshlst = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	freshlst = f(freshlst);
	lst = lst->next;
	first = freshlst;
	while (lst != NULL)
	{
		if (!(newelem = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		newelem = f(newelem);
		freshlst->next = newelem;
		freshlst = freshlst->next;
		lst = lst->next;
	}
	return (first);
}
