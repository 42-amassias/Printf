/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _decimal_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 06:53:46 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:16:59 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_decimal_printer(va_list *list, t_format *fmt)
{
	int	n;

	n = va_arg(*list, int);
	return (__number_printer(fmt, (long) n));
}
