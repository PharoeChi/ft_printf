/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:37:47 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/04 17:19:26 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)str)[i] == (unsigned char)c)
			return ((void*)(str + i));
		i++;
	}
	return (NULL);
}
