/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:03:09 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/02 15:07:32 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlower(unsigned long long num)
{
	int		len;

	len = 0;
	if (num >= 16)
	{
		len += ft_hexlower(num / 16);
	}
	if (num % 16 > 9)
		len += ft_putchar_fd((num % 16) - 10 + 'a', 1);
	else
		len += ft_putchar_fd((num % 16) + '0', 1);
	return (len);
}

int	ft_hexhigher(unsigned int num)
{
	int		len;

	len = 0;
	if (num >= 16)
	{
		len += ft_hexhigher(num / 16);
	}
	if (num % 16 > 9)
		len += ft_putchar_fd((num % 16) - 10 + 'A', 1);
	else
		len += ft_putchar_fd((num % 16) + '0', 1);
	return (len);
}
