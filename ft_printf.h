/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchiang <bchiang@42singapore.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:22:19 by bchiang           #+#    #+#             */
/*   Updated: 2025/12/15 13:14:28 by bchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	handle_format(char specifier, va_list *ap);
int	put_char(int c);
int	put_string(char *str);
int	put_number(long n, int base);
int	put_numbercaps(long n, int base);
int	put_uint_max(unsigned long num, int base);
int	put_pointer(void *ptr);
int	put_hex_lower(unsigned long int c);
int	put_hex_upper(unsigned long int c);

#endif
