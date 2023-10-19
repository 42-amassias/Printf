/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _string_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:58:39 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 23:03:20 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "libft.h"

int	__print_string(t_format *fmt, char *str)
{
	int			len;

	len = ft_strlen(str);
	fmt->width -= len;
	if (fmt->width < 0)
		fmt->width = 0;
	len += fmt->width;
	if (FMT__LEFT_JUSTIFY(*fmt))
		ft_putstr_fd(str, 1);
	while (fmt->width-- > 0)
		ft_putchar_fd(' ', 1);
	if (!FMT__LEFT_JUSTIFY(*fmt))
		ft_putstr_fd(str, 1);
	return (len);
}

int	_string_printer(va_list *list, t_format *fmt)
{
	char	*str;

	str = va_arg(*list, char *);
	if (str == NULL)
		str = (char *) "(null)";
	return (__print_string(fmt, str));
}
