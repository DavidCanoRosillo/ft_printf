/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:00:24 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/01/28 17:48:14 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static long	reverse(long num)
{
	long	rev_num;

	rev_num = 0;
	while (num > 0)
	{
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return (rev_num);
}

static	int	digits_n(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_category_u_fd(unsigned int n, int fd)
{
	long	ascii;
	long	copy;
	int		i;
	int		res;

	res = 0;
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	copy = reverse (n);
	i = digits_n(n);
	res += i;
	while (copy != 0)
	{
		ascii = copy % 10 + 48;
		ft_putchar_fd(ascii, fd);
		copy = copy / 10;
		i--;
	}
	while (i-- > 0)
		ft_putchar_fd('0', fd);
	return (res);
}
