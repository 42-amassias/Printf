/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _unsigned_printer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:33:38 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 22:51:06 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_unsigned_printer(va_list *list, t_format *fmt)
{
	unsigned int	n;

	n = va_arg(*list, unsigned int);
	fmt->flags &= ~(FMT_FLAG__ALIGN_SIGN | FMT_FLAG__FORCE_SIGN);
	return (__number_printer(fmt, (long) n));
}
