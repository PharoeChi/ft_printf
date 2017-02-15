/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:39:46 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/16 13:39:47 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_convert_dlong(t_print *flag, va_list *vars)
{
	char		c;
	char		*value;
	size_t		count;
	intmax_t	number;

	c = flag->type;
	count = 0;
	if (c == 'D')
	{
		number = va_arg(*vars, intmax_t);
		number = (long)number;
		number = ft_handle_negative(number, flag);
		value = ft_itoa_base(number, "0123456789", 10);
		ft_precision_int_value(&value, flag);
		count += ft_print_flag(value, flag);
		ft_free(value);
	}
	return (count);
}

size_t	ft_convert_ulong(t_print *flag, va_list *vars)
{
	char		c;
	char		*value;
	size_t		count;
	intmax_t	number;

	c = flag->type;
	count = 0;
	if (c == 'U')
	{
		number = va_arg(*vars, uintmax_t);
		number = (unsigned long)number;
		value = ft_itoa_base(number, "0123456789", 10);
		ft_precision_int_value(&value, flag);
		count += ft_print_flag(value, flag);
		ft_free(value);
	}
	return (count);
}

size_t	ft_convert_olong(t_print *flag, va_list *vars)
{
	char		c;
	char		*value;
	size_t		count;
	intmax_t	number;

	c = flag->type;
	count = 0;
	if (c == 'O')
	{
		number = va_arg(*vars, uintmax_t);
		number = (unsigned long)number;
		value = ft_itoa_base(number, "01234567", 8);
		ft_precision_int_value(&value, flag);
		flag->minus_flag = 0;
		flag->plus_flag = 0;
		count += ft_print_flag(value, flag);
		ft_free(value);
	}
	return (count);
}
