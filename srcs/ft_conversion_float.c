/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 14:20:04 by lbogar            #+#    #+#             */
/*   Updated: 2017/02/15 14:20:05 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

double  ft_round(t_print *flag)
{
  int     i;
  double  round;
  double  divisor;

  i = 0;
  round = 1;
  divisor = 10;
  while (i < (flag->precision + 1))
  {
    round /= divisor;
    i++;
  }
  return (round);
}

char    *ft_float_to_string(double number, t_print *flag)
{
  char      *string;
  char      *characteristic;
  int       i;

  i = 0;
  number += ft_round(flag);
  characteristic = ft_itoa_base((uintmax_t)number, "0123456789", 10);
  string = ft_strnew(ft_strlen(characteristic) + flag->precision + 1);
  while (characteristic[i])
  {
    string[i] = characteristic[i];
    i++;
  }
  string[i++] = '.';
  while (i <= (int)ft_strlen(characteristic) + flag->precision)
  {
    number -= (uintmax_t)number;
    number *= 10;
    string[i] = (uintmax_t)number + '0';
    i++;
  }
  return (string);
}

size_t	ft_convert_float(t_print *flag, va_list *vars)
{
  char		*value;
	size_t	count;
	double  number;

  count = 0;
  if (flag->precision_found == 0)
    flag->precision = 6;
  else
    flag->precision = ft_min(flag->precision, 500);
	number = va_arg(*vars, double);
  if (number < 0)
  {
    number = (double)number * -1;
    flag->negative = 1;
  }
	value = ft_float_to_string(number, flag);
	count += ft_print_flag(value, flag);
	ft_free(value);
	return (count);
}
