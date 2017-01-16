/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 20:03:28 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/10 20:03:30 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int     ft_str_intlen(const char *format, size_t i, size_t close)
{
	int len;

	len = 0;
	while (i < close && ft_isdigit(format[i]) == 1)
	{
		len++;
		i++;
	}
	return (len);
}

int   ft_find_width(const char *format, t_print *flag)
{
	size_t  i;

	i = flag->open;
	while (i < flag->close)
	{
		if (format[i] == '.')
			return (0);
		if (format[i] == '0' && ft_isdigit(format[i + 1]) == 0)
			i++;
		if (ft_isdigit(format[i]) == 1)
		{
			flag->width_index = i;
			return (1);
		}
		if (format[i] == '*')
		{
			flag->width_index = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int   ft_find_precision(const char *format, t_print *flag)
{
	size_t  i;

	i = flag->open;
	while (i < flag->close)
	{
		if (format[i] == '.')
		{
			flag->precision_index = i;
			flag->precision_found = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int   ft_parse_width(const char *format, t_print *flag, va_list *vars)
{
	size_t  len;
	char    *width;

	if (ft_find_width(format, flag) == 0)
		return (0);
	if (format[flag->width_index] == '*')
	{
		flag->width = va_arg(*vars, int);
		flag->width_found = 1;
		return (1);
	}
	if (ft_isdigit(format[flag->width_index]) == 1)
	{
		len = ft_str_intlen(format, flag->width_index, flag->close);
		width = ft_strsub(format, flag->width_index, len);
		flag->width = ft_atoi(width);
		flag->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}

int   ft_parse_precision(const char *format, t_print *flag, va_list *vars)
{
	size_t  len;
	char    *precision;

	if (ft_find_precision(format, flag) == 0)
		return (0);
	if (format[(flag->precision_index + 1)] == '*')
	{
		flag->precision = va_arg(*vars, int);
		return (1);
	}
	if (ft_isdigit(format[(flag->precision_index + 1)]) == 1)
	{
		flag->precision_index += 1;
		len = ft_str_intlen(format, flag->precision_index, flag->close);
		precision = ft_strsub(format, flag->precision_index, len);
		flag->precision = ft_atoi(precision);
		free(precision);
		return (1);
	}
	return (-1);
}
