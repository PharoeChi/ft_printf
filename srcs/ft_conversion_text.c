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

#include "ft_printf.h"

size_t	ft_convert_char(t_print *flag, va_list *vars)
{
	char	c;

	(void)flag;
	c = va_arg(*vars, int);
	write(1, &c, 1);
	return (1);
}

size_t	ft_convert_string(t_print *flag, va_list *vars)
{
	size_t	count;
	char	*str;

	(void)flag;
	count = 0;
	str = va_arg(*vars, char*);
	count = write(1, str, ft_strlen(str));
	return (count);
}

size_t	ft_convert_escape(t_print *flag, va_list *vars)
{
	char c;

	(void)flag;
	(void)vars;
	c = '%';
	write(1, &c, 1);
	return (1);
}
