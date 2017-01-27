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

size_t  ft_print_width_escape(char *value, t_print *flag)
{
	size_t count;
	int    len;
	char   *padding;

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

size_t  ft_print_flag_escape(char *value, t_print *flag)
{
	size_t  count;

	count = 0;
	if (flag->minus_flag == 1)
	{
		count += write(1, value, ft_strlen(value));
		count += ft_print_width_escape(value, flag);
	}
	else
	{
		count += ft_print_width_escape(value, flag);
		count += write(1, value, ft_strlen(value));
	}
	return (count);
}

size_t	ft_convert_escape(t_print *flag, va_list *vars)
{
	size_t	count;
	char		*escape;;

	(void)vars;
	count = 0;
	escape = "%";
	count += ft_print_flag_escape(escape, flag);
	return (count);
}
