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

void ft_putwchar(wchar_t c)
{
  if (c <= 0x7F)
    ft_putchar(c);
  else if (c <= 0x7FF)
  {
    ft_putchar((c >> 6) + 0xC0);
    ft_putchar((c & 0x3F) + 0x80);
  }
  else if (c <= 0xFFFF)
  {
    ft_putchar((c >> 12) + 0xE0);
    ft_putchar(((c >> 6) & 0x3F) + 0x80);
    ft_putchar((c & 0x3F) + 0x80);
  }
  else if (c <= 0x10FFFF)
  {
    ft_putchar((c >> 18) + 0xF0);
    ft_putchar(((c >> 12) & 0x3F) + 0x80);
    ft_putchar(((c >> 6) & 0x3F) + 0x80);
    ft_putchar((c & 0x3F) + 0x80);
  }
  return ;
}

size_t  ft_wstrlen(wchar_t *wstr)
{
  size_t len;

  len = 0;
  while(*wstr)
  {
    if (*wstr <= 0x7F)
      len++;
    else if (*wstr <= 0x7FF)
      len += 2;
    else if (*wstr <= 0xFFFF)
      len += 3;
    else if (*wstr <= 0x10FFFF)
      len += 4;
    wstr++;
  }
  return (len);
}

size_t  ft_putnwstr(wchar_t *wstr, size_t len)
{
  size_t count;
  size_t i;

  count = 0;
  i = 0;
  while (*wstr && i < len)
  {
    if (*wstr <= 0x7F)
      len++;
    else if (*wstr <= 0x7FF)
      len += 2;
    else if (*wstr <= 0xFFFF)
      len += 3;
    else if (*wstr <= 0x10FFFF)
      len += 4;
    if (i < len)
      ft_putwchar(*wstr);
    wstr++;
  }
  return (count);
}

size_t  ft_print_wstr_width(t_print *flag, size_t len)
{
	size_t count;
	char   *padding;

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

size_t	ft_convert_wstring(t_print *flag, va_list *vars)
{
  size_t  count;
  wchar_t *wstr;
  int     len;

  count = 0;
  wstr = va_arg(*vars, wchar_t*);
  len = ft_wstrlen(wstr);
  if (flag->precision_found && flag->precision < len)
    len = flag->precision;
  if (flag->width_found && flag->minus_flag && flag->width > len)
    count += ft_print_wstr_width(flag, flag->width);
  count += ft_putnwstr(wstr, len);
  if (flag->width_found && flag->minus_flag == 0 && flag->width > len)
    count += ft_print_wstr_width(flag, flag->width);
  return (count);
}
