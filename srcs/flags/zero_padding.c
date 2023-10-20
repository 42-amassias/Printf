/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_padding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:34:53 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:35:29 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	fmt__zero_padding(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__ZERO_PADDING) != 0);
}
