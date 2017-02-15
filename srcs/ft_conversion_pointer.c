/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 00:44:09 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 00:44:11 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_width_pointer(char *value, t_print *flag)
{
	size_t	count;
	int		len;
	char	*padding;

	len = ft_max(flag->width, (ft_strlen(value) + 2)) - (ft_strlen(value) + 2);
	if (len == 0)
		return (0);
	if (flag->zero_flag == 1 && flag->minus_flag == 0)
	{
		padding = ft_strnew(len);
		ft_strset(padding, '0', 0, len);
		count = write(1, padding, len);
		free(padding);
	}
	else
	{
		padding = ft_strnew(len);
		ft_strset(padding, ' ', 0, len);
		count = write(1, padding, len);
		free(padding);
	}
	return (count);
}

size_t	ft_print_flag_pointer(char *value, t_print *flag)
{
	size_t	count;

	count = 0;
	if (flag->zero_flag == 1)
	{
		count += write(1, "0x", 2);
		count += ft_print_width_pointer(value, flag);
		count += write(1, value, ft_strlen(value));
	}
	else if (flag->minus_flag == 1)
	{
		count += write(1, "0x", 2);
		count += write(1, value, ft_strlen(value));
		count += ft_print_width_pointer(value, flag);
	}
	else
	{
		count += ft_print_width_pointer(value, flag);
		count += write(1, "0x", 2);
		count += write(1, value, ft_strlen(value));
	}
	return (count);
}

size_t	ft_convert_pointer(t_print *flag, va_list *vars)
{
	char		*value;
	size_t		count;
	uintmax_t	number;

	count = 0;
	number = va_arg(*vars, uintmax_t);
	value = ft_itoa_base(number, "0123456789abcdef", 16);
	if (number == 0 && flag->precision_found == 1 && flag->precision == 0)
	{
		count += write(1, "0x", 2);
		ft_free(value);
		return (count);
	}
	ft_precision_int_value(&value, flag);
	count += ft_print_flag_pointer(value, flag);
	ft_free(value);
	return (count);
}
