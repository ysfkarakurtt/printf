/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:14:16 by ykarakur          #+#    #+#             */
/*   Updated: 2023/12/13 12:30:07 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	format_specifier(va_list arglist, char format)
{
	int	len;

	len = -1;
	if (format == 'c')
		len = ft_putchar(va_arg(arglist, int));
	else if (format == 's')
		len = ft_putstr(va_arg(arglist, char *));
	else if (format == 'p')
		len = ft_putptr(va_arg(arglist, unsigned long), 1);
	else if (format == 'd' || format == 'i')
		len = ft_putnbr(va_arg(arglist, int));
	else if (format == 'u')
		len = ft_unsigned(va_arg(arglist, unsigned int));
	else if (format == 'x' || format == 'X')
		len = ft_hex(va_arg(arglist, unsigned int), format);
	else if (format == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	arglist;
	int		len;
	int		i;
	int		tmp;

	va_start(arglist, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			tmp = format_specifier(arglist, str[i]);
			if (tmp == -1)
				return (-1);
			len += tmp - 1;
		}
		else if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
		len++;
	}
	va_end(arglist);
	return (len);
}
