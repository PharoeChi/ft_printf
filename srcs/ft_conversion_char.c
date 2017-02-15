/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:58:44 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/09 12:58:45 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_print_width_char(t_print *flag)
{
	size_t	count;
	int		len;
	char	*padding;

	len = ft_max(flag->width, 1) - 1;
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

size_t	ft_print_flag_char(char *value, t_print *flag)
{
	size_t	count;

	count = 0;
	if (flag->minus_flag == 1)
	{
		count += write(1, value, 1);
		count += ft_print_width_char(flag);
	}
	else
	{
		count += ft_print_width_char(flag);
		count += write(1, value, 1);
	}
	return (count);
}

size_t	ft_convert_char(t_print *flag, va_list *vars)
{
	size_t		count;
	char		c;

	count = 0;
	c = va_arg(*vars, int);
	if (flag->precision > 0 && c != '\0')
	{
		count += write(1, "*", 1);
		return (count);
	}
	else
		count += ft_print_flag_char(&c, flag);
	return (count);
}
