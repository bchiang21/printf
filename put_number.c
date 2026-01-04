/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:03:36 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/11 11:04:08 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_number(long n, int base)
{
	char	*symbols;
	int		result;

	symbols = "0123456789abcdef";
	result = 0;
	if (base < 2 || base > 16)
		return (0);
	if (n < 0)
	{
		result += put_char('-');
		n = -n;
	}
	if (n >= base)
		result += put_number(n / base, base);
	result += put_char(symbols[n % base]);
	return (result);
}
