/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbogar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 10:04:00 by lbogar            #+#    #+#             */
/*   Updated: 2016/12/16 10:04:35 by lbogar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>

typedef struct		s_print
{
	size_t			open;
	size_t			close;
	char			type;
	int				width;
	int				width_found;
	int				width_wild_found;
	size_t		width_open;
	size_t		width_close;
	int				precision;
	int				precision_found;
	int				precision_wild_found;
	size_t		precision_index;
	int				negative;
	int				hash_flag;
	int				zero_flag;
	int				minus_flag;
	int				plus_flag;
	int				space_flag;
	int				h_len;
	int				hh_len;
	int				l_len;
	int				ll_len;
	int				j_len;
	int				z_len;
	int				empty_flag;
	int				unterminated_flag;
}					t_print;

typedef size_t		(*t_convert)(t_print *flag, va_list *vars);

int						ft_initialize_flag(t_print *flag);
int   				ft_parse_width(const char *format, t_print *flag, va_list *vars);
int   				ft_parse_precision(const char *format, t_print *flag, va_list *vars);
int       		ft_widthlen_prefix(int len, t_print *flag);
int						ft_assign_flag(const char *format, t_print *flag, va_list *vars);
int						ft_scan_input(const char *format, va_list *vars);
int						ft_dispatcher(t_print *flag, va_list *vars);
size_t				ft_convert_pointer(t_print *flag, va_list *vars);
size_t				ft_convert_int(t_print *flag, va_list *vars);
size_t				ft_convert_uint(t_print *flag, va_list *vars);
size_t				ft_convert_octal(t_print *flag, va_list *vars);
size_t				ft_convert_hex(t_print *flag, va_list *vars);
size_t				ft_convert_base(t_print *flag, va_list *vars);
size_t				ft_convert_char(t_print *flag, va_list *vars);
size_t				ft_convert_string(t_print *flag, va_list *vars);
size_t				ft_convert_escape(t_print *flag, va_list *vars);
size_t				ft_convert_dlong(t_print *flag, va_list *vars);
size_t				ft_convert_ulong(t_print *flag, va_list *vars);
size_t				ft_convert_olong(t_print *flag, va_list *vars);
uintmax_t			ft_unsigned_int_length(uintmax_t number, t_print *flag);
intmax_t			ft_signed_int_length(intmax_t number, t_print *flag);
char					*ft_text_length(t_print *flag, char *text);
char  				*ft_precision_int_value(char *value, t_print *flag);
intmax_t  		ft_handle_negative(intmax_t number, t_print *flag);
size_t    		ft_handle_zero(t_print *flag);
void      		ft_valid_unsigned_prefix(t_print *flag);
size_t  			ft_print_width(char *value, t_print *flag);
size_t    		ft_print_prefix(t_print *flag);
size_t  			ft_print_flag(char *value, t_print *flag);
int						ft_printf(const char *format, ...);
int						ft_atoi(const char *str);
char					*ft_itoa_base(uintmax_t number, char *base_chars, size_t base);
char					*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
int						ft_strcmp(const char *s1, const char *s2);
void					ft_strset(char *string, char c, size_t start, size_t end);
char					*ft_strsub(char const *s, unsigned int start, size_t len);
char					*ft_strcpy(char *dst, const char *src);
int						ft_max(int x, int y);
int						ft_min(int x, int y);
int						ft_isdigit(int c);
void					*ft_memalloc(size_t size);
#endif
