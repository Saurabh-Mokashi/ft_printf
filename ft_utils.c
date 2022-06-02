/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 17:33:58 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/02 15:07:12 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_percent(void)
{
	return (ft_putchar_fd('%', 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], 1);
		i++;
	}
	return (i);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// size_t	ft_strlcpy(char *destination, const char *source, size_t n)
// {
// 	size_t			i;
// 	unsigned int	len;

// 	len = ft_strlen(source);
// 	if (!n)
// 		return (len);
// 	i = 0;
// 	while (source[i] && i < n - 1)
// 	{
// 		destination[i] = source[i];
// 		i++;
// 	}
// 	destination[i] = '\0';
// 	return (len);
// }

// int ft_getlen(long int n)
// {
// 	int i;

// 	i = 0;
// 	if (n < 0)
// 		i++;
// 	while (n > 0)
// 	{
// 		n /= 10;
// 		i++;
// 	}
// 	return (i);
// }

int	rec(long int n, int fd)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += rec(n / 10, fd);
	len += ft_putchar_fd(((long int)n % 10) + '0', fd);
	return (len);
}

int	ft_putnbr_fd(int p, int fd)
{
	long int	n;
	int			len;

	len = 0;
	if (p < 0)
	{
		if (p == -2147483648)
		{
			write (fd, "-2147483648", 11);
			return (11);
		}
		ft_putchar_fd('-', fd);
		n = (long int)(-1 * p);
		len = 1;
	}
	else
		n = (long int)(p);
	return (len + rec(n, fd));
}



// int	ft_putnbr_fd(int num, int fd)
// {
// 	int		len;
// 	char	s[10];

// 	ft_strlcpy(s, "0123456789", 10);
// 	len = 0;
// 	//printf("%d num is ", num);
// 	if (num < 0)
// 	{
// 		num *= -1;
// 		len++;
// 	}
// 	if (num > 10)
// 	{
// 		len += ft_putnbr_fd(num / 10, 1);
// 	}
// 	len += ft_putchar_fd(s[num % 10], 1);
// 	return (len);
// }
// int ft_putnbr(int n)
// {
// 	if (n < 0)
// 		return (1 + ft_putnbr_fd(n,1));
// 	else
// 		return (ft_putnbr_fd(n,1));
// }
// int ft_hexlower(unsigned long long num)
// {
// 	int		len;

// 	len = 0;
// 	if (num >= 16)
// 	{
// 		len += ft_hexlower(num / 16);
// 	}
// 	if (num % 16 > 9)
// 		len += ft_putchar_fd((num % 16) - 10 + 'a', 1);
// 	else
// 		len += ft_putchar_fd((num % 16) + '0', 1);
// 	return (len);
// }

// int ft_hexhigher(unsigned int num)
// {
// 	int		len;

// 	len = 0;
// 	if (num >= 16)
// 	{
// 		len += ft_hexhigher(num / 16);
// 	}
// 	if (num % 16 > 9)
// 		len += ft_putchar_fd((num % 16) - 10 + 'A', 1);
// 	else
// 		len += ft_putchar_fd((num % 16) + '0', 1);
// 	return (len);
// }
// int	ft_printp(unsigned long long p)
// {
// 	int	s;

// 	s = 0;
// 	s += ft_putstr("0x");
// 	// printf("\nthe number in int fprm is %d\n",(int)p);
// 	s += ft_hexlower(p);
// 	return (s);
// }
