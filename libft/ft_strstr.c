/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:37:45 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/07 09:37:48 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	const char *b;
	const char *l;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		b = big;
		l = little;
		while (*l && *b == *l)
		{
			l++;
			b++;
		}
		if (*l == '\0')
			return ((char*)big);
		big++;
	}
	return (NULL);
}
