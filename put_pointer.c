/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:04:40 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/15 17:01:49 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_pointer(void *ptr)
{
	unsigned long	addr;
	int				count;

	if (!ptr)
		return ((int)write(1, "0x0", 3));
	addr = (unsigned long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += put_hex_lower(addr);
	return (count);
}
