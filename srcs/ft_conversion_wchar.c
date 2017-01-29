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

size_t  ft_convert_wchar(t_print *flag, va_list *vars)
{
  wchar_t wchar;

  flag->return_error = 1;
  wchar = va_arg(*vars, wchar_t);
  if (wchar <= 0x7F)
  {
    if (flag->width_found && flag->minus_flag == 0)
      ft_print_width("c", flag);
    ft_putchar(wchar);
    if (flag->width_found && flag->minus_flag == 0)
      ft_print_width("c", flag);
    return (0);
  }
  else
  {
    flag->exit = 1;
    return (0);
  }
}
