/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _decimal_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:53:46 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 08:32:26 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "libft.h"

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
	if (!FMT__LEFT_JUSTIFY(*fmt) && FMT__ZERO_PADDING(*fmt))
		padd('0', fmt->width);
	print_number((unsigned long) n);
	if (FMT__LEFT_JUSTIFY(*fmt))
		padd(' ', fmt->width);
}

int	__number_printer(t_format *fmt, long n)
{
	int	size;

	size = len(n);
	if (n < 0 || FMT__FORCE_SIGN(*fmt) || FMT__ALIGN_SIGN(*fmt))
		++size;
	fmt->width -= size;
	if (fmt->width < 0)
		fmt->width = 0;
	size += fmt->width;
	print(fmt, n);
	return (size);
}

int	_decimal_printer(va_list *list, t_format *fmt)
{
	int	n;

	n = va_arg(*list, int);
	return (__number_printer(fmt, (long) n));
}
