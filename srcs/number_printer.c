/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:13:08 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:18:44 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	len(long u)
{
	int	len;

	len = 1;
	if (u < 0)
		u = -u;
	while (u > 9)
	{
		++len;
		u /= 10;
	}
	return (len);
}

static void	print_number(unsigned long n)
{
	if (n > 9)
		print_number(n / 10);
	ft_putchar_fd('0' + n % 10, 1);
}

static void	print(t_format *fmt, long n)
{
	if (!FMT__ZERO_PADDING(*fmt) && !FMT__LEFT_JUSTIFY(*fmt))
		padd(' ', fmt->width);
	if (!FMT__FORCE_SIGN(*fmt) && FMT__ALIGN_SIGN(*fmt) && n >= 0)
		ft_putchar_fd(' ', 1);
	if (FMT__FORCE_SIGN(*fmt) && n >= 0)
		ft_putchar_fd('+', 1);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	padd('0', fmt->precision);
	print_number((unsigned long) n);
	if (FMT__LEFT_JUSTIFY(*fmt))
		padd(' ', fmt->width);
}

int	__number_printer(t_format *fmt, long n)
{
	int	number_size;

	number_size = 0 + len(n);
	fmt->precision = max(0, fmt->precision - number_size);
	if (n < 0 || FMT__ALIGN_SIGN(*fmt) || FMT__FORCE_SIGN(*fmt))
		++number_size;
	if (FMT__ZERO_PADDING(*fmt) && !FMT__LEFT_JUSTIFY(*fmt))
		fmt->precision = max(fmt->precision, max(0, fmt->width - number_size));
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	print(fmt, n);
	return (number_size + fmt->width + fmt->precision);
}