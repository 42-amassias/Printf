/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _string_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 03:58:39 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:18:13 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_string_printer(va_list *list, t_format *fmt)
{
	char	*str;

	str = va_arg(*list, char *);
	if (str == NULL)
		str = (char *) "(null)";
	return (__print_string(fmt, str));
}
