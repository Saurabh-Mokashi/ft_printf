/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:57:43 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/02 15:07:38 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbru(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_putnbru(n / 10);
	len += ft_putchar_fd((n % 10) + '0', 1);
	return (len);
}
