/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:24:47 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/12 19:24:48 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strset(char *string, char c, size_t start, size_t end)
{
	while (start < end)
	{
		string[start] = c;
		++start;
	}
}
