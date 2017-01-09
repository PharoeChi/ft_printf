/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:00:45 by lbogar            #+#    #+#             */
/*   Updated: 2016/11/09 23:00:46 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char const *s, char c)
{
	int			i;
	int			word_count;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (s[i + 1] == c || s[i + 1] == '\0')
				++word_count;
		i++;
	}
	return (word_count);
}

static int		ft_word_len(char const *s, char c)
{
	int			len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			i;

	i = 0;
	if (!s)
		return (0);
	array = (char**)malloc(sizeof(*array) * (ft_word_count(s, c) + 1));
	if (array == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			array[i] = ft_strsub(s, 0, ft_word_len(s, c));
			if (array[i] == NULL)
				return (NULL);
			s = s + ft_word_len(s, c);
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}
