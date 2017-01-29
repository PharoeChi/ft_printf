/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unterminated.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 00:44:09 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/21 00:44:11 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_isvalid(char c)
{
	if (c == '0' || c == '#' || c == '+' || c == '-' || c == ' ' || c == '%')
		return (0);
	else
		return (1);
}

int		ft_skip_flag(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open + 1;
	while (format[i])
	{
		if (ft_isvalid(format[i]) == 1)
		{
			flag->close = i - 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_width_only(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open + 1;
	while (format[i])
	{
		//printf("checking outer while char: %c\n", format[i]);
		if (ft_isdigit(format[i]) == 1 || format[i] == '*')
		{
			//printf("checking inner if char: %c\n", format[i]);
			while (ft_isdigit(format[i]) == 1 || format[i] == '*')
			{
				//printf("checking inner while char: %c\n", format[i]);
				i++;
			}
			//printf("flag close char: %c\nflag close index: %zu\n", format[i - 1], i - 1);
			flag->close = i - 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_force_flag_close(const char *format, t_print *flag)
{
	size_t	i;

	i = flag->open;
	if (flag->unterminated_char != '0')
		return (1);
	if (ft_width_only(format, flag) == 1)
		return (2);
	if (ft_skip_flag(format, flag) == 1)
		return (3);
	if (flag->close == 0)
	{
		while (format[i])
			i++;
		flag->close = i;
	}
	return (0);
}

int   ft_find_w_ignore_p(const char *format, t_print *flag)
{
	size_t  i;

	i = flag->open;
	while (i <= flag->close)
	{
		if (ft_isdigit(format[i]) == 1 && format[i] != '0')
		{
			flag->width_open = i;
			flag->width_found = 1;
			return (1);
		}
		if (format[i] == '*')
		{
			flag->width_open = i;
			flag->width_found = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_parse_w_ignore_p(const char *format, t_print *flag, va_list *vars)
{
	size_t  len;
	char    *width;

	if (ft_find_w_ignore_p(format, flag) == 0)
		return (0);
	if (format[flag->width_open] == '*')
	{
		flag->width = va_arg(*vars, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus_flag = 1;
		}
		flag->width_found = 1;
		return (1);
	}
	if (ft_isdigit(format[flag->width_open]) == 1)
	{
		len = ft_str_intlen(format, flag->width_open, flag->close);
		width = ft_strsub(format, flag->width_open, len);
		flag->width = ft_atoi(width);
		flag->width_found = 1;
		free(width);
		return (1);
	}
	return (-1);
}

size_t	ft_parse_width_only(const char *format, t_print *flag, va_list *vars)
{
	char    *width;
	int			len;

	//printf("flag width open: %zu, flag close: %zu\n", flag->width_open, flag->close);
	//printf("flag width open char: %c, flag close char: %c\n", format[flag->width_open], format[flag->close]);
	if (format[flag->width_open] == '*')
	{
		flag->width = va_arg(*vars, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus_flag = 1;
		}
		flag->width -= 1;
		flag->width_found = 1;
		//printf("width: %d\n", flag->width);
		return (1);
	}
	if (ft_isdigit(format[flag->width_open]) == 1)
	{
		len = ft_str_intlen(format, flag->width_open, (flag->close + 1));
		width = ft_strsub(format, flag->width_open, len);
		flag->width = ft_atoi(width) - 1;
		flag->width_found = 1;
		free(width);
		//printf("width: %d\n", flag->width);
		return (1);
	}
	return (-1);
}

size_t	ft_print_width_only(t_print *flag)
{
	size_t	count;
	char   *padding;

	count = 0;
	if (flag->zero_flag == 1)
	{
		padding = ft_strnew(flag->width);
		ft_strset(padding, '0', 0, flag->width);
		count = write(1, padding, flag->width);
		free(padding);
	}
	else
	{
		padding = ft_strnew(flag->width);
		ft_strset(padding, ' ', 0, flag->width);
		count = write(1, padding, flag->width);
		free(padding);
	}
	return (count);
}

size_t	ft_process_unterm(const char *format, t_print *flag, va_list *vars)
{
	size_t	count;
	int			ret;

	count = 0;
	if ((ret = ft_force_flag_close(format, flag)) == 0)
	{
		flag->exit = 1;
		return (0);
	}
	if (ret == 2)
	{
		ft_prefix_parser(format, flag);
		ft_find_w_ignore_p(format, flag);
		ft_parse_width_only(format, flag, vars);
		count += ft_print_width_only(flag);
		return (count);
	}
	if (ret == 3)
	{
		return (count);
	}
	ft_prefix_parser(format, flag);
	ft_parse_w_ignore_p(format, flag, vars);
	count += ft_print_flag_string(&flag->unterminated_char, flag);
	return (count);
}
