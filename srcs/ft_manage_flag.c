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

#include "libftprintf.h"

void		ft_free(char *string)
{
	if (string == NULL)
		return ;
	else
		free(string);
}

/*
** Initialize all the variables in the main struct
*/

void		ft_initialize_flag(t_print *flag)
{
	flag->open = 0;
	flag->close = 0;
	flag->type = '0';
	flag->width = 0;
	flag->width_found = 0;
	flag->width_wild_found = 0;
	flag->width_open = 0;
	flag->width_close = 0;
	flag->precision = 0;
	flag->precision_found = 0;
	flag->precision_wild_found = 0;
	flag->precision_index = 0;
	flag->negative = 0;
	flag->hash_flag = 0;
	flag->zero_flag = 0;
	flag->minus_flag = 0;
	flag->plus_flag = 0;
	flag->space_flag = 0;
	flag->h_len = 0;
	flag->hh_len = 0;
	flag->l_len = 0;
	flag->ll_len = 0;
	flag->j_len = 0;
	flag->z_len = 0;
	flag->unterminated_char = '0';
}

uintmax_t	ft_unsigned_int_length(uintmax_t number, t_print *flag)
{
	if (flag->z_len == 1)
		number = (size_t)number;
	else if (flag->j_len == 1)
		number = (uintmax_t)number;
	else if (flag->ll_len == 1)
		number = (unsigned long long)number;
	else if (flag->l_len == 1)
		number = (unsigned long)number;
	else if (flag->hh_len == 1)
		number = (unsigned char)number;
	else if (flag->h_len == 1)
		number = (unsigned short int)number;
	else
		number = (unsigned int)number;
	return (number);
}

intmax_t	ft_signed_int_length(intmax_t number, t_print *flag)
{
	if (flag->z_len == 1)
		number = (size_t)number;
	else if (flag->j_len == 1)
		number = (intmax_t)number;
	else if (flag->ll_len == 1)
		number = (long long)number;
	else if (flag->l_len == 1)
		number = (long)number;
	else if (flag->hh_len == 1)
		number = (signed char)number;
	else if (flag->h_len == 1)
		number = (short int)number;
	else
		number = (int)number;
	return (number);
}
