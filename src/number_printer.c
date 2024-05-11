/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:13:08 by amassias          #+#    #+#             */
/*   Updated: 2023/10/24 03:29:00 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#include <stdio.h>

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

static void	print(t_format *fmt, long n, int pn)
{
	if (!fmt__left_justify(fmt))
		putnchar(' ', fmt->width);
	if (!fmt__force_sign(fmt) && fmt__align_sign(fmt) && n >= 0)
		ft_putchar_fd(' ', 1);
	if (fmt__force_sign(fmt) && n >= 0)
		ft_putchar_fd('+', 1);
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', 1);
	}
	putnchar('0', fmt->precision);
	if (pn)
		print_number((unsigned long) n);
	if (fmt__left_justify(fmt))
		putnchar(' ', fmt->width);
}

int	number_printer(t_format *fmt, long n)
{
	int	number_size;

	if (fmt__precision(fmt) && fmt->precision == 0 && n == 0)
		number_size = 0;
	else
		number_size = len(n);
	fmt->precision -= number_size;
	if (n < 0 || fmt__align_sign(fmt) || fmt__force_sign(fmt))
		++number_size;
	if (fmt__zero_padding(fmt)
		&& !fmt__left_justify(fmt)
		&& !fmt__precision(fmt))
		fmt->precision = fmt->width - number_size;
	fmt->precision = max(0, fmt->precision);
	fmt->width = max(0, fmt->width - number_size - fmt->precision);
	print(fmt, n, number_size != 0);
	return (number_size + fmt->width + fmt->precision);
}
