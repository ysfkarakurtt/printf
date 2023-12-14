/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykarakur <ykarakur@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:31:29 by ykarakur          #+#    #+#             */
/*   Updated: 2023/12/13 12:31:43 by ykarakur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	format_specifier(va_list arglist, char format);
int	ft_putnbr(int number);
int	ft_unsigned(unsigned int w);
int	ft_putstr(char *str);
int	ft_hex(unsigned int d, char w);
int	ft_putptr(unsigned long ptr, int i);
#endif
