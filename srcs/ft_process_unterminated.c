/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unterminated.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 00:44:09 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 00:44:11 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_force_flag_close(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open;
	if (flag->unterminated_char != '0')
		return (1);
	if (ft_width_only(format, flag) == 1)
		return (2);
	if (ft_skip_flag(format, flag) == 1)
		return (3);
	if (flag->close == 0)
	{
		while (format[i])
			i++;
		flag->close = i;
	}
	return (0);
}

size_t	ft_process_unterm(const char *format, t_print *flag, va_list *vars)
{
	size_t	count;
	int		ret;

	count = 0;
	if ((ret = ft_force_flag_close(format, flag)) == 0)
	{
		flag->exit = 1;
		return (0);
	}
	if (ret == 2)
	{
		ft_prefix_parser(format, flag);
		ft_find_w_ignore_p(format, flag);
		ft_parse_width_only(format, flag, vars);
		count += ft_print_width_only(flag);
		return (count);
	}
	if (ret == 3)
	{
		return (count);
	}
	ft_prefix_parser(format, flag);
	ft_parse_w_ignore_p(format, flag, vars);
	count += ft_print_flag_string(&flag->unterminated_char, flag);
	return (count);
}
