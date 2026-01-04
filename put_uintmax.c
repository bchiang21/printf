/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unit_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 10:05:51 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/10 11:29:08 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_uint_max(unsigned long num, int base)
{
	char	*digits;
	char	buffer[50];
	int		i;
	int		result;

	if (base < 2 || base > 16)
		return (0);
	digits = "0123456789abcdef";
	i = 49;
	result = 0;
	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = digits[num % base];
		num /= base;
	}
	while (buffer[i])
	{
		write(1, &buffer[i], 1);
		result++;
		i++;
	}
	return (result);
}
