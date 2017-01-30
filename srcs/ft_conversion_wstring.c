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

size_t  ft_wstrlen(wchar_t *wstring)
{
  size_t count;

  count = 0;
  while (*wstring)
  {
    if (*wstring <= 0x7F)
    {
      count += 1;
      wstring++;
    }
    else if (*wstring <= 0x7FF)
    {
      count += 2;
      wstring += 2;
    }
    else if (*wstring <= 0xFFFF)
    {
      count += 3;
      wstring += 3;
    }
    else if (*wstring <= 0x10FFFF)
    {
      count += 4;
      wstring += 4;
    }
    else
      wstring++;
  }
  return(count);
}

size_t	ft_convert_wstring(t_print *flag, va_list *vars)
{
  size_t    count;
  size_t    len;
  wchar_t   *wstring;
  char      *copy;

  count = 0;
  wstring = va_arg(*vars, wchar_t*);
  len = ft_wstrlen(wstring);
  copy = ft_strnew(len);
  if (flag->width_found && flag->minus_flag == 0)
    count += ft_print_width(copy, flag);
  while(*wstring)
  {
    ft_putwchar(*wstring++);
  }
  count += len;
  if (flag->width_found && flag->minus_flag == 1)
    count += ft_print_width(copy, flag);
  free(copy);
  return (count);
}
