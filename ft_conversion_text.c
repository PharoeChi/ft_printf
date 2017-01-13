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

#include "libft.h"

size_t	ft_convert_char(t_print *flag, va_list *vars)
{
	size_t	count;
	char		c;

	count = 0;
	c = va_arg(*vars, int);
	if (c == '\0')
	{
		count = write(1, "", 1);
	}
	else
	{
	//c = *(ft_text_length(flag, &c));
	count = ft_print_flag(&c, flag);
	}
	return (count);
}

size_t	ft_convert_string(t_print *flag, va_list *vars)
{
	size_t	count;
	char	*string;

	count = 0;
	string = va_arg(*vars, char*);
	if (string == NULL)
	{
		count = write(1, "", 1);
	}
	else
	{
		//string = ft_text_length(flag, str);
		string = ft_precision_text_value(string, flag);
		count = ft_print_flag(string, flag);
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
	count = ft_print_flag(escape, flag);
	return (count);
}
