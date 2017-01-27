/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:21:24 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/13 14:21:26 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

intmax_t  ft_handle_negative(intmax_t number, t_print *flag)
{
	if (number < 0)
	{
		number *= -1;
		flag->negative = 1;
	}
	return (number);
}

size_t    ft_handle_zero(t_print *flag)
{
	size_t count;

	count = 0;
	if (flag->precision_found == 1 && flag->precision == 0)
		count += ft_print_width("", flag);
	else
	{
		count += write(1, "0", 1);
		count += ft_print_width("0", flag);
	}
	return (count);
}

void      ft_valid_unsigned_prefix(t_print *flag)
{
	flag->space_flag = 0;
	flag->plus_flag = 0;
}

int       ft_widthlen_prefix(int len, t_print *flag)
{
	char c;

	c = flag->type;
	if ((c == 'o' || c == 'O') && flag->hash_flag == 1)
		return (len - 1);
	if (c == 'p')
		return (len - 2);
	if ((c == 'x' || c == 'X') && flag->hash_flag == 1)
		return (len - 2);
	if (flag->negative == 1)
		return (len - 1);
	if (flag->negative == 0 && flag->plus_flag == 1)
		return (len - 1);
	if (flag->negative == 0 && flag->plus_flag == 0
			 && flag->space_flag == 1 && c != '%')
		return (len - 1);
	return (len);
}

size_t    ft_print_prefix(t_print *flag)
{
	size_t  count;
	char    c;

	count = 0;
	c = flag->type;
	if ((c == 'o' || c == 'O') && flag->hash_flag == 1)
		count += write(1, "0", 1);
	if (c == 'p')
		count += write(1, "0x", 2);
	if ((c == 'x') && flag->hash_flag == 1)
		count += write(1, "0x", 2);
	if ((c == 'X') && flag->hash_flag == 1)
		count += write(1, "0X", 2);
	if (flag->negative == 1)
		count += write(1, "-", 1);
	if (flag->negative == 0 && flag->plus_flag == 1)
		count += write(1, "+", 1);
	if (flag->negative == 0 && flag->plus_flag == 0
			 && flag->space_flag == 1 && c != '%')
		count += write(1, " ", 1);
	return (count);
}
