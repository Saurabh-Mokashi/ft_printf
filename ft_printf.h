/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smokashi <smokashi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:18:52 by smokashi          #+#    #+#             */
/*   Updated: 2022/06/02 14:11:05 by smokashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_percent(void);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *destination, const char *source, size_t n);
int		ft_hexlower(unsigned long long num);
int		ft_hexhigher(unsigned int num);
int		rec(long int n, int fd);
int		ft_putnbr_fd(int p, int fd);
int		ft_putnbru(unsigned int n);
int		ft_printp(unsigned long long p);
#endif