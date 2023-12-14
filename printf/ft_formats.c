/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:30:50 by ykarakur          #+#    #+#             */
/*   Updated: 2023/12/13 18:35:07 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int number)
{
	int	len;
	int	tmp;

	len = 0;
	if (number == 0)
		return (write(1, "0", 1));
	if (number == -2147483648)
		return (write(1, "-2147483648", 11));
	if (number < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		number *= -1;
	}
	if (number >= 10)
	{
		tmp = ft_putnbr(number / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[number % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_unsigned(unsigned int w)
{
	int	len;
	int	tmp;

	len = 0;
	if (w >= 10)
	{
		tmp = ft_unsigned(w / 10);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789"[w % 10], 1) == -1)
		return (-1);
	return (len + 1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex(unsigned int d, char w)
{
	int	len;
	int	tmp;

	len = 0;
	if (d >= 16)
	{
		tmp = ft_hex(d / 16, w);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (w == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[d % 16], 1) == -1)
			return (-1);
	}
	if (w == 'x')
	{
		if (write(1, &"0123456789abcdef"[d % 16], 1) == -1)
			return (-1);
	}
	return (len + 1);
}

int	ft_putptr(unsigned long ptr, int i)
{
	int	len;
	int	tmp;

	len = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		len += 2;
	}
	if (ptr >= 16)
	{
		tmp = ft_putptr(ptr / 16, i);
		if (tmp == -1)
			return (-1);
		len += tmp;
	}
	if (write(1, &"0123456789abcdef"[ptr % 16], 1) == -1)
		return (-1);
	return (len + 1);
}
