/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 02:55:50 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:28:50 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	_char_printer(va_list *list, t_format *fmt)
{
	int	len;

	if (fmt->width <= 0)
		fmt->width = 1;
	len = fmt->width--;
	if (fmt__left_justify(fmt))
		ft_putchar_fd(va_arg(*list, int), 1);
	while (fmt->width--)
		ft_putchar_fd(' ', 1);
	if (!fmt__left_justify(fmt))
		ft_putchar_fd(va_arg(*list, int), 1);
	return (len);
}
