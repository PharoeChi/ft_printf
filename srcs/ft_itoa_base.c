/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 12:53:51 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 12:53:52 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen_base(size_t number, size_t base)
{
	size_t	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		++i;
	}
	return (i);
}

char	*ft_itoa_base(int number, char *base_chars, size_t base)
{
	char	*string;
	size_t	len;
	int		negative;

	negative = 0;
	len = ft_intlen_base(number, base) + negative;
	if (number < 0)
	{
		len += 1;
		negative = 1;
		number *= -1;
	}
	if ((string = ft_strnew(len--)) == NULL)
		return (NULL);
	if (number == 0)
		string[0] = base_chars[0];
	while (number)
	{
		string[len--] = base_chars[(number % base)];
		number /= base;
	}
	if (negative)
		string[0] = '-';
	return (string);
}
