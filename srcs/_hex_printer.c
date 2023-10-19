/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _hex_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:36:08 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 07:49:55 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "libft.h"

#define U_CHARSET "0123456789ABCDEFX"
#define L_CHARSET "0123456789abcdefx"

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
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(charset[sizeof(L_CHARSET) - 2], 1);
	}
	if (!FMT__LEFT_JUSTIFY(*fmt) && FMT__ZERO_PADDING(*fmt))
		padd('0', fmt->width);
	print_hex(charset, n);
	if (FMT__LEFT_JUSTIFY(*fmt))
		padd(' ', fmt->width);
}

int	__hex_printer(t_format *fmt, size_t n, int u)
{
	int	size;

	size = len(n);
	if (FMT__HEX_PREFIX(*fmt))
		size += 2;
	if (FMT__FORCE_SIGN(*fmt) || FMT__ALIGN_SIGN(*fmt))
		++size;
	fmt->width -= size;
	if (fmt->width < 0)
		fmt->width = 0;
	size += fmt->width;
	print(fmt, n, u);
	return (size);
}
