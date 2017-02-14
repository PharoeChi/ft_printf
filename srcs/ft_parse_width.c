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

int		ft_str_intlen(const char *format, size_t i, size_t close)
{
	int		len;

	len = 0;
	while (i < close && ft_isdigit(format[i]) == 1)
	{
		len++;
		i++;
	}
	return (len);
}

int		ft_str_intlen_rev(const char *format, t_print *flag)
{
	int		len;
	size_t	i;

	len = 0;
	i = flag->width_close;
	while (i > flag->open && ft_isdigit(format[i]) == 1)
	{
		len++;
		i--;
	}
	flag->width_open = i + 1;
	return (len);
}

void	ft_skip_wild_arg_width(const char *format, t_print *flag, va_list *vars)
{
	int		skip;
	size_t	i;

	i = flag->open;
	if (flag->width_wild_found == 0)
	{
		while (i < flag->close && format[i] != '.')
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

int		ft_find_width(const char *format, t_print *flag)
{
	size_t	i;

	if (ft_find_precision(format, flag) == 1)
		i = flag->precision_index - 1;
	else
		i = flag->close;
	while (i > flag->open)
	{
		if (ft_isdigit(format[i]) == 1)
		{
			flag->width_close = i;
			flag->width_found = 1;
			return (1);
		}
		if (format[i] == '*')
		{
			flag->width_close = i;
			flag->width_wild_found = 1;
			flag->width_found = 1;
			return (1);
		}
		i--;
	}
	return (0);
}

int		ft_parse_width(const char *format, t_print *flag, va_list *vars)
{
	size_t	len;
	char	*width;

	if (ft_find_width(format, flag) == 0)
		return (0);
	if (format[flag->width_close] == '*')
	{
		flag->width = va_arg(*vars, int);
		if (flag->width < 0)
			flag->width = ft_handle_negative(flag->width, flag);
		flag->width_found = 1;
		return (1);
	}
	ft_skip_wild_arg_width(format, flag, vars);
	if (ft_isdigit(format[flag->width_close]) == 1)
	{
		len = ft_str_intlen_rev(format, flag);
		width = ft_strsub(format, flag->width_open, len);
		flag->width = ft_atoi(width);
		flag->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}
