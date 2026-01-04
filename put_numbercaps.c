/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_numbercaps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:05:22 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/15 17:01:21 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_numbercaps(long n, int base)
{
	char	*symbols;
	int		result;

	symbols = "0123456789ABCDEF";
	result = 0;
	if (base < 2 || base > 16)
		return (0);
	if (n < 0)
	{
		result += put_char('-');
		n = -n;
	}
	if (n >= base)
		result += put_numbercaps(n / base, base);
	result += put_char(symbols[n % base]);
	return (result);
}
