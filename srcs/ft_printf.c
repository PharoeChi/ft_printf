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

#include "libftprintf.h"

/*
** Dispatches replacement calls to the correct translations function,
** i.e. ft_itoa_base.
*/

void		ft_initialize_dispatcher(t_convert *dispatcher)
{
	dispatcher['%'] = &ft_convert_escape;
	dispatcher['s'] = &ft_convert_string;
	dispatcher['S'] = &ft_convert_string;
	dispatcher['c'] = &ft_convert_char;
	dispatcher['C'] = &ft_convert_wchar;
	dispatcher['i'] = &ft_convert_int;
	dispatcher['d'] = &ft_convert_int;
	dispatcher['D'] = &ft_convert_dlong;
	dispatcher['u'] = &ft_convert_uint;
	dispatcher['U'] = &ft_convert_ulong;
	dispatcher['o'] = &ft_convert_octal;
	dispatcher['O'] = &ft_convert_olong;
	dispatcher['x'] = &ft_convert_hex;
	dispatcher['X'] = &ft_convert_hex;
	dispatcher['p'] = &ft_convert_pointer;
}

/*
** This functions uses several tricks to make/use an array of function pointers.
** First, it memallocs an array of 256, the total number of values in the ASCII
** table, so that any char input will at least have a value of NULL. Second, it
** makes dispatcher a static variable so it persists out of scope. Third, it
** compresses allocating the memory and initializing the array into a nice 'if'
** statement. Finaly, the return is the char'th position in the array, which is
** a clever way of accessing the pointer to the correct type conversion.
*/

t_convert	ft_get_flag(char c)
{
	static	t_convert *dispatcher;

	if (dispatcher == NULL)
	{
		dispatcher = ft_memalloc(sizeof(*dispatcher) * 256);
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
	flag->exit = 0;
	flag->return_error = 0;
	while ((ret = ft_assign_flag(format, flag, vars)) != 0)
	{
		if (ret == 1)
		{
			count += write(1, format, flag->open);
			format += (flag->open + (flag->close - flag->open) + 1);
			count += ft_process_flag(flag, vars);
			ft_initialize_flag(flag);
		}
		else if (ret == 2)
		{
			count += write(1, format, flag->open);
			count += ft_process_unterm(format, flag, vars);
			if (flag->exit == 1)
				return (count);
			format += (flag->open + (flag->close - flag->open) + 1);
			ft_initialize_flag(flag);
		}
		else if (ret == 3)
		{
			ft_convert_wchar(flag, vars);
			if (flag->exit == 1)
				return (-1);
		}
		else
			return (-1);
	}
	count += write(1, format, ft_strlen(format));
	if (flag->return_error == 1)
		return (-1);
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
