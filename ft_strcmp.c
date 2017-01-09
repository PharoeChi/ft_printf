/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:59:59 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/07 11:00:00 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *cmp1;
	unsigned char *cmp2;

	cmp1 = (unsigned char*)s1;
	cmp2 = (unsigned char*)s2;
	while (*cmp1 == *cmp2 && *cmp1 && *cmp2)
	{
		++cmp1;
		++cmp2;
	}
	return (*cmp1 - *cmp2);
}
