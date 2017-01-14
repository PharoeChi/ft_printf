/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 13:24:59 by lbogar            #+#    #+#             */
/*   Updated: 2017/01/12 13:25:00 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *ft_precision_int_value(char *value, t_print *flag)
{
  int     len;
  char    *precision_value;
  char    *temp;

  len = ft_max(flag->precision, ft_strlen(value)) - ft_strlen(value);
  if (len == 0 && value[0] == '0' && flag->precision_found == 1)
  {
    free(value);
    value = "";
    return (value);
  }
  if (len == 0)
    return (value);
  precision_value =ft_strnew(flag->precision);
  temp = precision_value;
  ft_strset(precision_value, '0', 0, len);
  precision_value += len;
  precision_value = ft_strcpy(precision_value, value);
  free(value);
  precision_value = temp;
  return (precision_value);
}

char  *ft_precision_text_value(char *value, t_print *flag)
{
  int     len;
  char    *precision_value;

  len = ft_min(flag->precision, ft_strlen(value));
  precision_value = ft_strsub(value, 0, len);
  return (precision_value);
}

size_t  ft_print_width(char *value, t_print *flag)
{
  size_t count;
  int    len;
  char   *padding;

  len = ft_max(flag->width, ft_strlen(value)) - ft_strlen(value);
  if (len == 0)
    return (0);
  len = ft_widthlen_prefix(len, flag);
  if (flag->zero_flag == 1 && flag->minus_flag == 0
    && flag->precision_found == 0)
  {
    padding = ft_strnew(len);
    ft_strset(padding, '0', 0, len);
    count = write(1, padding, len);
    free(padding);
  }
  else
  {
    padding = ft_strnew(len);
    ft_strset(padding, ' ', 0, len);
    count = write(1, padding, len);
    free(padding);
  }
  return (count);
}

size_t  ft_print_flag(char *value, t_print *flag)
{
  size_t  count;

  count = 0;
  if (flag->zero_flag == 1 && flag->minus_flag == 0)
  {
    count += ft_print_prefix(flag);
    count += ft_print_width(value, flag);
    count += write(1, value, ft_strlen(value));
  }
  else if (flag->minus_flag == 1)
  {
    count += ft_print_prefix(flag);
    count += write(1, value, ft_strlen(value));
    count += ft_print_width(value, flag);
  }
  else
  {
    count += ft_print_width(value, flag);
    count += ft_print_prefix(flag);
    count += write(1, value, ft_strlen(value));
  }
  return (count);
}
