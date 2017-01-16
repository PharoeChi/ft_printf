/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:44:10 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/01 14:44:11 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char *s;
	char *d;

	s = (char*)src;
	d = (char*)dst;
	while (n > 0 && *s != c)
	{
		--n;
		*d++ = *s++;
	}
	if (n > 0)
	{
		*d++ = c;
		return ((void*)d);
	}
	else
		return (NULL);
}
