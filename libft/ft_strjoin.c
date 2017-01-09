/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:12:06 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/08 13:12:06 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*temp;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char*)malloc(sizeof(char) * size);
	if (join == NULL)
		return (NULL);
	temp = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	join = temp;
	return (join);
}
