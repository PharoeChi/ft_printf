/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_temp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:56:45 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/10 16:56:45 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = ft_strlen(s) + 1;
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char*)s + i);
	}
	return (NULL);
}
