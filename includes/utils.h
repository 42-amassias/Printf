/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:16:23 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:48:44 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"

# include <stdarg.h>

# define FMT_FLAG__LEFT_JUSTIFY 0b000001
# define FMT_FLAG__FORCE_SIGN 0b000010
# define FMT_FLAG__ALIGN_SIGN 0b000100
# define FMT_FLAG__HEX_PREFIX 0b001000
# define FMT_FLAG__ZERO_PADDING 0b010000
# define FMT_FLAG__PRECISION 0b100000

typedef struct s_format {
	int		width;
	int		precision;
	char	flags;
	char	specifier;
}	t_format;

void	putnchar(char c, int count);
int		max(int a, int b);
int		min(int a, int b);

int		fmt__left_justify(t_format *fmt);
int		fmt__force_sign(t_format *fmt);
int		fmt__align_sign(t_format *fmt);
int		fmt__hex_prefix(t_format *fmt);
int		fmt__zero_padding(t_format *fmt);
int		fmt__precision(t_format *fmt);

int		hex_printer(t_format *fmt, size_t n, int u);
int		string_printer(t_format *fmt, char *str);
int		number_printer(t_format *fmt, long n);

int		_char_printer(va_list *list, t_format *fmt);
int		_string_printer(va_list *list, t_format *fmt);
int		_pointer_printer(va_list *list, t_format *fmt);
int		_decimal_printer(va_list *list, t_format *fmt);
int		_integer_printer(va_list *list, t_format *fmt);
int		_unsigned_printer(va_list *list, t_format *fmt);
int		_lo_hex_printer(va_list *list, t_format *fmt);
int		_up_hex_printer(va_list *list, t_format *fmt);

#endif