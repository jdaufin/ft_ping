/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynarray_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdaufin <jdaufin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:22:37 by jdaufin           #+#    #+#             */
/*   Updated: 2020/11/19 15:43:31 by jdaufin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ping.h"

static _Bool	extend_array(t_dynarray *parray)
{
	size_t	new_size;

	new_size = parray->capacity + dynarray_getbuflen();
	if (!ft_realloc((void **)&(parray->array), parray->capacity, new_size))
		return (0);
	parray->capacity = new_size;
	return (1);
}

_Bool			dynarray_add(t_dynarray *parray, double val)
{
	size_t	val_index;

	if (!(parray && parray->array))
		return (0);
	if ((parray->last_val_index + 1) >= parray->capacity)
		if (!extend_array(parray))
			return (0);
	val_index = (parray->last_val_index)++;
	parray->array[val_index] = val;
	return (1);
}