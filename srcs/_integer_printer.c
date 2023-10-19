/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _integer_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 08:34:21 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_integer_printer(va_list *list, t_format *fmt)
{
	int	n;

	n = va_arg(*list, int);
	return (__number_printer(fmt, (long) n));
}
