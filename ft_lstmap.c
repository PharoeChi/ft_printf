/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:55:21 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/16 11:55:22 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *ret;

	ret = NULL;
	while (lst)
	{
		tmp = f(lst);
		if (!ret)
		{
			ret = tmp;
			new = ret;
			ret->next = NULL;
		}
		else
		{
			ret->next = tmp;
			tmp->next = NULL;
			ret = ret->next;
		}
		lst = lst->next;
	}
	return (new);
}
