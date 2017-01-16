/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 10:45:14 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/08 10:45:15 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*mapped;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	mapped = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (mapped == NULL)
		return (NULL);
	while (s[i])
	{
		mapped[i] = f(s[i]);
		i++;
	}
	mapped[i] = '\0';
	return (mapped);
}
