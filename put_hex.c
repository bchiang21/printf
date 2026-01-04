/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 10:31:54 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/15 17:00:41 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_hex_lower(unsigned long int n)
{
	char	buf[16];
	char	*base;
	int		i;
	int		count;

	base = "0123456789abcdef";
	if (n == 0)
		return ((int)write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buf[i] = base[n % 16];
		n /= 16;
		i++;
	}
	count = i;
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (count);
}

int	put_hex_upper(unsigned long int n)
{
	char	buf[16];
	char	*base;
	int		i;
	int		count;

	base = "0123456789ABCDEF";
	if (n == 0)
		return ((int)write(1, "0", 1));
	i = 0;
	while (n > 0)
	{
		buf[i] = base[n % 16];
		n /= 16;
		i++;
	}
	count = i;
	while (i > 0)
	{
		i--;
		write(1, &buf[i], 1);
	}
	return (count);
}
