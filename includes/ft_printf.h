/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:49:30 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 23:03:25 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# include <stdarg.h>

# define FMT_FLAG__LEFT_JUSTIFY 0b00001
# define FMT_FLAG__FORCE_SIGN 0b00010
# define FMT_FLAG__ALIGN_SIGN 0b00100
# define FMT_FLAG__HEX_PREFIX 0b01000
# define FMT_FLAG__ZERO_PADDING 0b10000

# define FMT__LEFT_JUSTIFY(fmt) (((fmt).flags & FMT_FLAG__LEFT_JUSTIFY) != 0)
# define FMT__FORCE_SIGN(fmt) (((fmt).flags & FMT_FLAG__FORCE_SIGN) != 0)
# define FMT__ALIGN_SIGN(fmt) (((fmt).flags & FMT_FLAG__ALIGN_SIGN) != 0)
# define FMT__HEX_PREFIX(fmt) (((fmt).flags & FMT_FLAG__HEX_PREFIX) != 0)
# define FMT__ZERO_PADDING(fmt) (((fmt).flags & FMT_FLAG__ZERO_PADDING) != 0)

typedef struct s_format {
	char	flags;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

void	padd(char c, int count);

int		__hex_printer(t_format *fmt, size_t n, int u);
int		__print_string(t_format *fmt, char *str);
int		__number_printer(t_format *fmt, long n);

int		_char_printer(va_list *list, t_format *fmt);
int		_string_printer(va_list *list, t_format *fmt);
int		_pointer_printer(va_list *list, t_format *fmt);
int		_decimal_printer(va_list *list, t_format *fmt);
int		_integer_printer(va_list *list, t_format *fmt);
int		_unsigned_printer(va_list *list, t_format *fmt);
int		_lo_hex_printer(va_list *list, t_format *fmt);
int		_up_hex_printer(va_list *list, t_format *fmt);

int		ft_printf(const char *fmt, ...);

#endif