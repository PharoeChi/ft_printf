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
