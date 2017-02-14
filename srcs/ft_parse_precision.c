/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:33:47 by lbogar            #+#    #+#             */
/*   Updated: 2017/02/14 11:33:48 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_skip_wild_arg_prec(const char *format, t_print *flag, va_list *vars)
{
	int		skip;
	size_t	i;

	i = flag->precision_index + 1;
	if (flag->precision_wild_found == 0)
	{
		while (i < flag->close)
		{
			if (format[i] == '*')
			{
				skip = va_arg(*vars, int);
				return ;
			}
			i++;
		}
	}
}

int		ft_find_precision(const char *format, t_print *flag)
{
	size_t	i;

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

int		ft_parse_precision(const char *format, t_print *flag, va_list *vars)
{
	size_t	len;
	char	*precision;

	if (flag->precision_found == 0)
		return (0);
	if (format[(flag->precision_index + 1)] == '*')
	{
		flag->precision = va_arg(*vars, int);
		flag->precision_wild_found = 1;
		if (flag->precision < 0)
			flag->precision_found = 0;
		return (1);
	}
	ft_skip_wild_arg_prec(format, flag, vars);
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
