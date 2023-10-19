/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _pointer_printer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 05:25:18 by amassias          #+#    #+#             */
/*   Updated: 2023/10/19 07:02:40 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "libft.h"

int	_pointer_printer(va_list *args, t_format *fmt)
{
	void	*ptr;
	size_t	n;

	ptr = va_arg(*args, void *);
	n = *(long *)&ptr;
	if (!n)
		return (__print_string(fmt, "(nil)"));
	fmt->flags |= FMT_FLAG__HEX_PREFIX;
	return (__hex_printer(fmt, n, 0));
}
