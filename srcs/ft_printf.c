/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:09:45 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:18:27 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#define SPECIFIERS "cspdiuxX%"
#define FLAGS "-+ #0"

typedef int		(*t_type_printer)(va_list *, t_format *);

t_type_printer	g_printers[] = {
	_char_printer,
	_string_printer, _pointer_printer, _decimal_printer,
	_integer_printer, _unsigned_printer, _lo_hex_printer, _up_hex_printer,
};

void	read_number(const char **str, int *value_ptr)
{
	int	x;

	x = 0;
	while (**str && ft_isdigit(**str))
	{
		x = 10 * x + **str - '0';
		++(*str);
	}
	*value_ptr = x;
}

int	read_format(t_format *fmt, const char **fmt_ptr)
{
	char	*x;

	ft_bzero(fmt, sizeof(t_format));
	while (1)
	{
		x = ft_strchr(FLAGS, *(*fmt_ptr));
		if (!x)
			break ;
		++(*fmt_ptr);
		*((char *)&fmt->flags) |= 1 << (x - FLAGS);
	}
	read_number(fmt_ptr, &fmt->width);
	if (**fmt_ptr && **fmt_ptr == '.')
	{
		++(*fmt_ptr);
		read_number(fmt_ptr, &fmt->precision);
		fmt->flags |= FMT_FLAG__PRECISION;
	}
	x = ft_strchr(SPECIFIERS, **fmt_ptr);
	if (!*(*fmt_ptr)++ || !x)
		return (1);
	fmt->specifier = *x;
	return (0);
}

int	handle(const char **fmt_ptr, va_list *list)
{
	t_format		format;
	t_type_printer	printer;
	int				len;
	const char		*start;

	if (read_format(&format, fmt_ptr))
	{
		start = *fmt_ptr;
		while (*start != '%')
			--start;
		len = *fmt_ptr - start;
		while (start < *fmt_ptr)
			ft_putchar_fd(*start++, 1);
		return (len);
	}
	if (format.specifier == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	printer = g_printers[ft_strchr(SPECIFIERS, format.specifier) - SPECIFIERS];
	return (printer(list, &format));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		length;

	length = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt++ != '%')
		{
			++length;
			ft_putchar_fd(fmt[-1], 1);
			continue ;
		}
		length += handle(&fmt, &args);
	}
	va_end(args);
	return (length);
}
