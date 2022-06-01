/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:21:13 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/01 19:18:24 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	ft_getform(va_list ptr, char c)
{
	int	len;

	len = 0;
	if (c == 's')
		len += ft_putstr(va_arg(ptr, char *));
	else if (c == 'c')
		len += ft_putchar_fd(va_arg(ptr, int), 1);
	else if (c == 'p')
		len += ft_printp(va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (c == 'u')
		len += ft_putnbru(va_arg(ptr, unsigned int));
	else if (c == 'x')
		len += ft_hexlower(va_arg(ptr, int));
	else if (c == 'X')
		len += ft_hexhigher(va_arg(ptr, int));
	else if (c == '%')
		len += ft_percent();
	else
		len = 0;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	va_start (ptr, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_getform(ptr, format[i + 1]);
			i++;
		}
		else
			len += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ptr);
	return (len);
}
// int main()
// {
// 	// int len = ft_printf("%s","");
// 	// printf((" NULL %s NULL ", NULL);
// 	// len = ft_printf("%s","");
// 	// printf("\n%d",len);
// 	int len = printf("%p", 15);
// 	printf("%d\n",len);
// 	len = ft_printf("%p", 15);
// 	printf("%d",len);
// 	return (0);
// }