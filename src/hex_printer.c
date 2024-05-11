/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_printer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:36:08 by amassias          #+#    #+#             */
/*   Updated: 2023/10/24 05:03:59 by amassias         ###   ########.fr       */
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

static void	print(t_format *fmt, size_t n, int pn, int u)
{
	char	*charset;

	charset = L_CHARSET;
	if (u)
		charset = U_CHARSET;
	if (!fmt__left_justify(fmt))
		putnchar(' ', fmt->width);
	if (fmt__hex_prefix(fmt)
		&& (!fmt__precision(fmt) || fmt->precision >= 0 || n))
		ft_putstr_fd(&charset[sizeof(L_CHARSET) - 3], 1);
	putnchar('0', fmt->precision);
	if (pn)
		print_hex(charset, n);
	if (fmt__left_justify(fmt))
		putnchar(' ', fmt->width);
}

int	hex_printer(t_format *fmt, size_t n, int u)
{
	int	number_size;
	int	prefix;

	if (fmt__precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = len(n);
	fmt->precision -= number_size;
	if (n == 0)
		fmt->flags &= ~FMT_FLAG__HEX_PREFIX;
	prefix = 2 * fmt__hex_prefix(fmt);
	if (prefix)
		fmt->width -= 2;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = max(0, fmt->precision);
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	print(fmt, n, number_size != 0, u);
	return (prefix + number_size + fmt->width + fmt->precision);
}
