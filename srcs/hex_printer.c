/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:36:08 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:18:36 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define U_CHARSET "0123456789ABCDEF0X"
#define L_CHARSET "0123456789abcdef0x"

static int	len(size_t n)
{
	int	len;

	len = 1;
	while (n > 0xf)
	{
		++len;
		n >>= 4;
	}
	return (len);
}

static void	print_hex(const char *charset, size_t n)
{
	if (n > 0xf)
		print_hex(charset, n >> 4);
	ft_putchar_fd(charset[n & 0xf], 1);
}

static void	print(t_format *fmt, size_t n, int u)
{
	char	*charset;

	charset = L_CHARSET;
	if (u)
		charset = U_CHARSET;
	if (!FMT__ZERO_PADDING(*fmt) && !FMT__LEFT_JUSTIFY(*fmt))
		padd(' ', fmt->width);
	if (!FMT__FORCE_SIGN(*fmt) && FMT__ALIGN_SIGN(*fmt))
		ft_putchar_fd(' ', 1);
	if (FMT__FORCE_SIGN(*fmt))
		ft_putchar_fd('+', 1);
	if (FMT__HEX_PREFIX(*fmt))
		ft_putstr_fd(&charset[sizeof(L_CHARSET) - 3], 1);
	padd('0', fmt->precision);
	print_hex(charset, n);
	if (FMT__LEFT_JUSTIFY(*fmt))
		padd(' ', fmt->width);
}

int	__hex_printer(t_format *fmt, size_t n, int u)
{
	int	number_size;
	int	prefix;

	if (n == 0)
		fmt->flags &= ~FMT_FLAG__HEX_PREFIX;
	prefix = 2 * FMT__HEX_PREFIX(*fmt);
	if (prefix)
		fmt->width -= 2;
	number_size = len(n);
	fmt->precision = max(0, fmt->precision - number_size);
	if (n < 0 || FMT__ALIGN_SIGN(*fmt) || FMT__FORCE_SIGN(*fmt))
		++number_size;
	if (FMT__ZERO_PADDING(*fmt) && !FMT__LEFT_JUSTIFY(*fmt))
		fmt->precision = max(fmt->precision, max(0, fmt->width - number_size));
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	print(fmt, n, u);
	return (prefix + number_size + fmt->width + fmt->precision);
}
