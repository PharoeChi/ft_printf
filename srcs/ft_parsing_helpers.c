/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:14:05 by lbogar            #+#    #+#             */
/*   Updated: 2017/02/14 11:14:06 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_false_flag(char c)
{
	if (c == 'y' || c == 'Y' || c == 'b' || c == 'B' || c == 'k' || c == 'K' ||
		c == 'm' || c == 'M' || c == 'r' || c == 'R' || c == 't' || c == 'T' ||
		c == 'w' || c == 'W' || c == 'H' || c == 'I' || c == 'J' || c == 'N' ||
		c == 'P' || c == 'Q' || c == 'V' || c == 'Z')
		return (1);
	else
		return (0);
}

int		ft_flag_char(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' ||
		c == 'c' || c == 'C' || c == '%')
		return (1);
	else
		return (0);
}

int		ft_isvalid(char c)
{
	if (c == '0' || c == '#' || c == '+' || c == '-' || c == ' ' || c == '%' ||
		c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (0);
	else
		return (1);
}

int		ft_skip_flag(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open + 1;
	while (format[i])
	{
		if (ft_isvalid(format[i]) == 1)
		{
			flag->close = i - 1;
			return (1);
		}
		i++;
	}
	return (0);
}
