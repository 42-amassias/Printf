/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:33:59 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:34:46 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	fmt__precision(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__PRECISION) != 0);
}
