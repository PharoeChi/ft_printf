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

// void ft_putwchar(wchar_t c)
// {
//   if (c <= 0x7F)
//     ft_putchar(c);
//   else if (c <= 0x7FF)
//   {
//     ft_putchar((c >> 6) + 0xC0);
//     ft_putchar((c & 0x3F) + 0x80);
//   }
//   else if (c <= 0xFFFF)
//   {
//     ft_putchar((c >> 12) + 0xE0);
//     ft_putchar(((c >> 6) & 0x3F) + 0x80);
//     ft_putchar((c & 0x3F) + 0x80);
//   }
//   else if (c <= 0x10FFFF)
//   {
//     ft_putchar((c >> 18) + 0xF0);
//     ft_putchar(((c >> 12) & 0x3F) + 0x80);
//     ft_putchar(((c >> 6) & 0x3F) + 0x80);
//     ft_putchar((c & 0x3F) + 0x80);
//   }
//   else
//     return ;
// }
//
// size_t	ft_convert_wchar(t_print *flag, va_list *vars)
// {
//   size_t  count;
//   wchar_t wchar;
//
//   count = 0;
//   wchar = va_arg(*vars, wchar_t);
//   if (wchar <= 0x7F)
//     count = 1;
//   else if (wchar <= 0x7FF)
//     count = 2;
//   else if (wchar <= 0xFFFF)
//     count = 3;
//   else if (wchar <= 0x10FFFF)
//     count = 4;
//   else
//     count = 0;
//   if (flag->width_found && flag->minus_flag == 0)
//     count += ft_print_width(ft_strnew(count), flag);
//   ft_putwchar(wchar);
//   if (flag->width_found && flag->minus_flag == 1)
//     count += ft_print_width(ft_strnew(count), flag);
//   return (count);
// }

void	ft_putwchar(wchar_t wchar)
{
  if (wchar <= 0x7F)
    ft_putchar(wchar);
  else if (wchar <= 0x7FF)
  {
    ft_putchar(wchar >> 6);
    ft_putchar(wchar);
  }
  else if (wchar <= 0xFFFF)
  {
    ft_putchar(wchar >> 12);
    ft_putchar(wchar >> 6);
    ft_putchar(wchar);
  }
  else if (wchar <= 0x10FFFF)
  {
    ft_putchar(wchar >> 18);
    ft_putchar(wchar >> 12);
    ft_putchar(wchar >> 6);
    ft_putchar(wchar);
  }
  else
    return ;
}

void	ft_convert_wchar(t_print *flag, va_list *vars)
{
  wchar_t wchar;
  size_t  count;

  (void)flag;
  flag->exit = 1;
  wchar = va_arg(*vars, wchar_t);
  if (wchar <= 0x7F)
    count = 1;
  else if (wchar <= 0x7FF)
    count = 2;
  else if (wchar <= 0xFFFF)
    count = 3;
  else if (wchar <= 0x10FFFF)
    count = 4;
  else
    count = 0;
  if (flag->width_found && flag->minus_flag == 0)
    ft_print_width(ft_strnew(count), flag);
  ft_putwchar(wchar);
  if (flag->width_found && flag->minus_flag == 1)
    ft_print_width(ft_strnew(count), flag);
}
