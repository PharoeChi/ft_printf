/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 13:00:33 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 13:00:34 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Initialize all the variables in the main struct
*/

int		ft_initialize_flag(t_print *flag)
{
	flag->open = 0;
	flag->close = 0;
	flag->type = '0';
	flag->hash_flag = 0;
	flag->zero_flag = 0;
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->h_len = 0;
	flag->hh_len = 0;
	flag->l_len = 0;
	flag->ll_len = 0;
	flag->j_len = 0;
	flag->z_len = 0;
	flag->empty_flag = 0;
	return (0);
}

uintmax_t	ft_unsigned_int_length(t_print *flag, uintmax_t number)
{
	if (flag->l_len == 1)
		number = (unsigned long)number;
	else if (flag->ll_len == 1)
		number = (unsigned long long)number;
	else if (flag->z_len == 1)
		number = (size_t)number;
	else if (flag->h_len == 1)
		number = (unsigned short int)number;
	else if (flag->hh_len == 1)
		number = (unsigned char)number;
	else if (flag->j_len == 1)
		number = (uintmax_t)number;
	else
		number = (unsigned int)number;
	return (number);
}

intmax_t	ft_signed_int_length(t_print *flag, intmax_t number)
{
	if (flag->l_len == 1)
		number = (long)number;
	else if (flag->ll_len == 1)
		number = (long long)number;
	else if (flag->z_len == 1)
		number = (size_t)number;
	else if (flag->h_len == 1)
		number = (short int)number;
	else if (flag->hh_len == 1)
		number = (signed char)number;
	else if (flag->j_len == 1)
		number = (intmax_t)number;
	else
		number = (int)number;
	return (number);
}

/*
char	*ft_text_length(t_print *flag, char *text)
{
	if ((flag->type == 'c' || flag->type == 'C') && flag->l_len == 0)
		*text = (int)*text;
	if ((flag->type == 'c' || flag->type == 'C') && flag->l_len == 1)
		*text = (wint_t)*text;
	if ((flag->type == 's' || flag->type == 'S') && flag->l_len == 1)
		text = (wchar_t*)text;
	return (text);
	}
*/
