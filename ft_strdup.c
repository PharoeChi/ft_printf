/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:46:27 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/04 14:46:27 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
	{
		return (NULL);
	}
	if (ft_strlen(s1) == 0)
	{
		s2[i] = '\0';
		return (s2);
	}
	while (s1[i])
	{
		s2[i] = s1[i];
		++i;
	}
	s2[i] = '\0';
	return (s2);
}
