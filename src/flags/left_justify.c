/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:31:33 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:37:46 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	fmt__left_justify(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__LEFT_JUSTIFY) != 0);
}
