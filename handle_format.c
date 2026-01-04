/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:44:38 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/15 16:31:55 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	handle_format(char specifier, va_list *ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += put_char(va_arg(*ap, int));
	else if (specifier == 's')
		count += put_string(va_arg(*ap, char *));
	else if (specifier == 'p')
		count += put_pointer(va_arg(*ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += put_number((long)va_arg(*ap, int), 10);
	else if (specifier == 'u')
		count += put_uint_max(
				(unsigned long)va_arg(*ap, unsigned int), 10);
	else if (specifier == 'x')
		count += put_hex_lower(va_arg(*ap, unsigned int));
	else if (specifier == 'X')
		count += put_hex_upper(va_arg(*ap, unsigned int));
	else
		count += write(1, &specifier, 1);
	return (count);
}
