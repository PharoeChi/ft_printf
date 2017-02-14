/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_only.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:45:07 by lbogar            #+#    #+#             */
/*   Updated: 2017/02/14 11:45:09 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_width_only(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open + 1;
	while (format[i])
	{
		if (ft_isdigit(format[i]) == 1 || format[i] == '*')
		{
			while (ft_isdigit(format[i]) == 1 || format[i] == '*')
				i++;
			flag->close = i - 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_find_w_ignore_p(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open;
	while (i <= flag->close)
	{
		if (ft_isdigit(format[i]) == 1 && format[i] != '0')
		{
			flag->width_open = i;
			flag->width_found = 1;
			return (1);
		}
		if (format[i] == '*')
		{
			flag->width_open = i;
			flag->width_found = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_parse_w_ignore_p(const char *format, t_print *flag, va_list *vars)
{
	size_t	len;
	char	*width;

	if (ft_find_w_ignore_p(format, flag) == 0)
		return (0);
	if (format[flag->width_open] == '*')
	{
		flag->width = va_arg(*vars, int);
		if (flag->width < 0)
			flag->width = ft_handle_negative(flag->width, flag);
		flag->width_found = 1;
		return (1);
	}
	if (ft_isdigit(format[flag->width_open]) == 1)
	{
		len = ft_str_intlen(format, flag->width_open, flag->close);
		width = ft_strsub(format, flag->width_open, len);
		flag->width = ft_atoi(width);
		flag->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}

size_t	ft_parse_width_only(const char *format, t_print *flag, va_list *vars)
{
	char	*width;
	int		len;

	if (format[flag->width_open] == '*')
	{
		flag->width = va_arg(*vars, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus_flag = 1;
		}
		flag->width -= 1;
		flag->width_found = 1;
		return (1);
	}
	if (ft_isdigit(format[flag->width_open]) == 1)
	{
		len = ft_str_intlen(format, flag->width_open, (flag->close + 1));
		width = ft_strsub(format, flag->width_open, len);
		flag->width = ft_atoi(width) - 1;
		flag->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}

size_t	ft_print_width_only(t_print *flag)
{
	size_t	count;
	char	*padding;

	count = 0;
	if (flag->zero_flag == 1)
	{
		padding = ft_strnew(flag->width);
		ft_strset(padding, '0', 0, flag->width);
		count = write(1, padding, flag->width);
		free(padding);
	}
	else
	{
		padding = ft_strnew(flag->width);
		ft_strset(padding, ' ', 0, flag->width);
		count = write(1, padding, flag->width);
		free(padding);
	}
	return (count);
}
