/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:12:50 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/16 10:12:60 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Dispatches replacement calls to the correct translations function,
** i.e. ft_itoa_base.
*/

void		ft_initialize_dispatcher(t_convert *dispatcher)
{
	dispatcher['%'] = &ft_convert_escape;
	dispatcher['s'] = &ft_convert_string;
	dispatcher['c'] = &ft_convert_char;
	dispatcher['i'] = &ft_convert_int;
	dispatcher['d'] = &ft_convert_int;
	dispatcher['u'] = &ft_convert_int;
	dispatcher['u'] = &ft_convert_int;
	dispatcher['o'] = &ft_convert_octal;
	dispatcher['O'] = &ft_convert_octal;
	dispatcher['x'] = &ft_convert_hex;
	dispatcher['X'] = &ft_convert_hex;
}

t_convert	ft_get_flag(char c)
{
	static	t_convert *dispatcher;

	if (dispatcher == NULL)
	{
		dispatcher = ft_memalloc(sizeof(*dispatcher) * 11);
		if (dispatcher != NULL)
			ft_initialize_dispatcher(dispatcher);
	}
	return (dispatcher[(int)c]);
}

size_t		ft_process_flag(t_print *flag, va_list *vars)
{
	size_t		count;
	t_convert	convert;

	convert = ft_get_flag(flag->type);
	count = convert(flag, vars);
	return (count);
}

/*
** Main function, calls all other sub-functions.
** Responsible for the final write.
*/

int			ft_scan_input(const char *format, va_list *vars)
{
	t_print	*flag;
	int		ret;
	size_t	count;

	count = 0;
	flag = (t_print*)malloc(sizeof(t_print));
	if (flag == NULL)
		return (-1);
	ft_initialize_flag(flag);
	while ((ret = ft_assign_flag(format, flag)) != 0)
	{
		if (ret == 1)
		{
			count += write(1, format, flag->open);
			format += (flag->open + (flag->close - flag->open) + 1);
			count += ft_process_flag(flag, vars);
		}
		else
			return (-1);
	}
	count += write(1, format, ft_strlen(format));
	return (count);
}

int			ft_printf(const char *format, ...)
{
	int		count;
	va_list	vars;

	va_start(vars, format);
	count = ft_scan_input(format, &vars);
	va_end(vars);
	return (count);
}
