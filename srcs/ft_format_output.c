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

#include "libftprintf.h"

void	ft_precision_int_value(char **value, t_print *flag)
{
	int		len;
	char	*temp;

	len = ft_max(flag->precision, ft_strlen(*value)) - ft_strlen(*value);
	if (flag->type == 'o' && flag->hash_flag == 1 && flag->precision >= 1)
		len -= 1;
	if (len == 0 && *value[0] == '0' && flag->precision_found == 1)
	{
		free(*value);
		temp = ft_strnew(0);
		*value = temp;
		return ;
	}
	if (len == 0)
		return ;
	temp = ft_strnew(flag->precision);
	ft_strset(temp, '0', 0, len);
	temp += len;
	temp = ft_strcpy(temp, *value);
	free(*value);
	*value = temp - len;
}

size_t	ft_print_width(char *value, t_print *flag)
{
	size_t	count;
	int		len;
	char	*padding;

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

size_t	ft_print_flag(char *value, t_print *flag)
{
	size_t	count;

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

size_t	ft_print_prefix(t_print *flag)
{
	size_t	count;
	char	c;

	count = 0;
	c = flag->type;
	if ((c == 'o' || c == 'O') && flag->hash_flag == 1)
		count += write(1, "0", 1);
	if (c == 'p')
		count += write(1, "0x", 2);
	if ((c == 'x') && flag->hash_flag == 1)
		count += write(1, "0x", 2);
	if ((c == 'X') && flag->hash_flag == 1)
		count += write(1, "0X", 2);
	if (flag->negative == 1)
		count += write(1, "-", 1);
	if (flag->negative == 0 && flag->plus_flag == 1)
		count += write(1, "+", 1);
	if (flag->negative == 0 && flag->plus_flag == 0
			&& flag->space_flag == 1 && c != '%')
		count += write(1, " ", 1);
	return (count);
}
