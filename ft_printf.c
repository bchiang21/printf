/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:53:04 by bchiang           #+#    #+#             */
/*   Updated: 2026/01/07 14:58:07 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	handle_sign(const char **sign, va_list *ap)
{
	int	count;

	count = 0;
	if (**sign != '%')
	{
		write(1, *sign, 1);
		(*sign)++;
		return (1);
	}
	(*sign)++;
	if (**sign == '\0')
		return (-1);
	if (**sign == '%')
	{
		(*sign)++;
		return ((int)write(1, "%", 1));
	}
	count = handle_format(**sign, ap);
	(*sign)++;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		check;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		check = handle_sign(&format, &ap);
		if (check == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += check;
	}
	va_end(ap);
	return (count);
}


/* #include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	ret1;
	int	ret2;

	char string[] = "hello";

	ft_printf("%s", null);
	
	ret1 = ft_printf("Hello %s!\n", "world");
	ret2 = printf("Hello %s!\n", "world");
	printf("ft_printf returned: %d\n", ret1);
	printf("printf returned   : %d\n\n", ret2);

	ret1 = ft_printf("Char: %c | Number: %d | Hex: %x\n", 'A', -42, 255);
	ret2 = printf("Char: %c | Number: %d | Hex: %x\n", 'A', -42, 255);
	printf("ft_printf returned: %d\n", ret1);
	printf("printf returned   : %d\n\n", ret2);

	ret1 = ft_printf("Pointer: %p | Percent: %%\n", NULL);
	ret2 = printf("Pointer: %p | Percent: %%\n", NULL);
	printf("ft_printf returned: %d\n", ret1);
	printf("printf returned   : %d\n", ret2);

	return (0);
} */
