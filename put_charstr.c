/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_charstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@student.42singapore.sg>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:25:28 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/15 17:00:12 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	put_string(char *str)
{
	int	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
