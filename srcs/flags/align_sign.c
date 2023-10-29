/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_sign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amassias <amassias@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 04:36:05 by amassias          #+#    #+#             */
/*   Updated: 2023/10/20 04:37:11 by amassias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	fmt__align_sign(t_format *fmt)
{
	return ((fmt->flags & FMT_FLAG__ALIGN_SIGN) != 0);
}
