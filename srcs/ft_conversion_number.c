/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coversion_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 00:44:09 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 00:44:11 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_convert_int(t_print *flag, va_list *vars)
{
	char	c;
	char	*str;
	size_t	count;
	int		number;

	c = flag->type;
	count = 0;
	if (c == 'i' || c == 'd' || c == 'u' || c == 'U')
	{
		number = va_arg(*vars, int);
		str = ft_itoa_base(number, "0123456789", 10);
		count = write(1, str, ft_strlen(str));
	}
	return (count);
}

size_t	ft_convert_octal(t_print *flag, va_list *vars)
{
	char	c;
	char	*str;
	size_t	count;
	int		number;

	count = 0;
	c = flag->type;
	if (c == 'o' || c == 'O')
	{
		number = va_arg(*vars, int);
		str = ft_itoa_base(number, "01234567", 8);
		count = write(1, str, ft_strlen(str));
	}
	return (count);
}

size_t	ft_convert_hex(t_print *flag, va_list *vars)
{
	char	c;
	char	*str;
	size_t	count;
	int		number;

	count = 0;
	c = flag->type;
	if (c == 'x')
	{
		number = va_arg(*vars, int);
		str = ft_itoa_base(number, "0123456789abcdef", 16);
		count = write(1, str, ft_strlen(str));
	}
	if (c == 'X')
	{
		number = va_arg(*vars, int);
		str = ft_itoa_base(number, "0123456789ABCDEF", 16);
		count = write(1, str, ft_strlen(str));
	}
	return (count);
}
