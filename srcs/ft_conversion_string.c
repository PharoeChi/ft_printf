/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_text.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 12:58:44 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/09 12:58:45 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_precision_text_value(char *value, t_print *flag)
{
	int		len;
	char	*precision_value;

	len = ft_min(flag->precision, ft_strlen(value));
	precision_value = ft_strsub(value, 0, len);
	return (precision_value);
}

size_t	ft_print_width_string(char *value, t_print *flag)
{
	size_t	count;
	int		len;
	char	*padding;

	if (value == NULL)
		len = ft_max(flag->width, 0);
	else
		len = ft_max(flag->width, ft_strlen(value)) - ft_strlen(value);
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

size_t	ft_print_flag_string(char *value, t_print *flag)
{
	size_t	count;

	count = 0;
	if (value == NULL)
	{
		count += ft_print_width_string(value, flag);
	}
	if (flag->minus_flag == 1)
	{
		count += write(1, value, ft_strlen(value));
		count += ft_print_width_string(value, flag);
	}
	else
	{
		count += ft_print_width_string(value, flag);
		count += write(1, value, ft_strlen(value));
	}
	return (count);
}

size_t	ft_convert_string(t_print *flag, va_list *vars)
{
	size_t	count;
	char	*string;

	count = 0;
	string = va_arg(*vars, char*);
	if ((string == NULL || ft_strcmp(string, "(null)") == 0)
		&& flag->zero_flag == 1)
	{
		count += ft_print_width_string(string, flag);
		return (count);
	}
	else if (string == NULL || ft_strcmp(string, "(null)") == 0)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	else
	{
		if (flag->precision_found == 1)
			string = ft_precision_text_value(string, flag);
		count = ft_print_flag_string(string, flag);
	}
	return (count);
}
