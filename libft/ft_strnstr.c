/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:30:13 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/07 10:30:13 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*b;
	const char	*l;
	size_t		i;

	if (*little == '\0')
		return ((char*)big);
	while (*big && len > 0)
	{
		b = big;
		l = little;
		i = len;
		while (*l && *b == *l && i--)
		{
			l++;
			b++;
		}
		if (*l == '\0')
			return ((char*)big);
		big++;
		--len;
	}
	return (NULL);
}
