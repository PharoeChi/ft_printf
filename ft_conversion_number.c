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

#include "libft.h"

size_t	ft_convert_int(t_print *flag, va_list *vars)
{
	char	c;
	char	*value;
	size_t	count;
	intmax_t	number;

	c = flag->type;
	count = 0;
	if (c == 'i' || c == 'd' || c == 'D')
	{
		number = va_arg(*vars, intmax_t);
		number = ft_signed_int_length(number, flag);
		number = ft_handle_negative(number, flag);
		value = ft_itoa_base(number, "0123456789", 10);
		value = ft_precision_int_value(value, flag);
		count += ft_print_flag(value, flag);
	}
	return (count);
}

size_t	ft_convert_uint(t_print *flag, va_list *vars)
{
	char	c;
	char	*value;
	size_t	count;
	uintmax_t		number;

	c = flag->type;
	count = 0;
	ft_valid_unsigned_prefix(flag);
	if (c == 'u' || c == 'U')
	{
		number = va_arg(*vars, uintmax_t);
		number = ft_unsigned_int_length(number, flag);
		value = ft_itoa_base(number, "0123456789", 10);
		value = ft_precision_int_value(value, flag);
		count = ft_print_flag(value, flag);
	}
	return (count);
}

size_t	ft_convert_octal(t_print *flag, va_list *vars)
{
	char	c;
	char	*value;
	size_t	count;
	uintmax_t		number;

	count = 0;
	c = flag->type;
	ft_valid_unsigned_prefix(flag);
	if (c == 'o' || c == 'O')
	{
		number = va_arg(*vars, uintmax_t);
		number = ft_unsigned_int_length(number, flag);
		value = ft_itoa_base(number, "01234567", 8);
		value = ft_precision_int_value(value, flag);
		count += ft_print_flag(value, flag);
	}
	return (count);
}

size_t	ft_convert_hex(t_print *flag, va_list *vars)
{
	char	c;
	char	*value;
	size_t	count;
	uintmax_t		number;

	count = 0;
	c = flag->type;
	ft_valid_unsigned_prefix(flag);
	if (c == 'x')
	{
		number = va_arg(*vars, uintmax_t);
		number = ft_unsigned_int_length(number, flag);
		value = ft_itoa_base(number, "0123456789abcdef", 16);
	}
	if (c == 'X')
	{
		number = va_arg(*vars, uintmax_t);
		number = ft_unsigned_int_length(number, flag);
		value = ft_itoa_base(number, "0123456789ABCDEF", 16);
	}
	if (number == 0)
	{
		count += ft_handle_zero(flag);
		return (count);
	}
	value = ft_precision_int_value(value, flag);
	count += ft_print_flag(value, flag);
	return (count);
}

size_t	ft_convert_pointer(t_print *flag, va_list *vars)
{
	char		*value;
	char		*prefix;
	size_t	count;
	uintmax_t			number;

	(void)flag;
	count = 0;
	prefix = "0x";
	number = va_arg(*vars, uintmax_t);
	value = ft_itoa_base(number, "0123456789abcdef", 16);
	count = write(1, prefix, 2);
	count += write(1, value, ft_strlen(value));
	return (count);
}
