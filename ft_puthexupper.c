/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:30:52 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/21 18:22:52 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_puthex_upper(int nbr)
{
	char	upper_hex[6];
	char	c;

	upper_hex[0] = 'A';
	upper_hex[1] = 'B';
	upper_hex[2] = 'C';
	upper_hex[3] = 'D';
	upper_hex[4] = 'E';
	upper_hex[5] = 'F';
	if (nbr >= 10)
		write(1, upper_hex + nbr - 10, 1);
	else
	{
		c = nbr + 48;
		write(1, &c, 1);
	}
}

static long	reverse(long num)
{
	long	rev_num;

	rev_num = 0;
	while (num > 0)
	{
		rev_num = rev_num * 16 + num % 16;
		num = num / 16;
	}
	return (rev_num);
}

static int	digits_n(unsigned int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static int	print_zero(int fd)
{
	write(fd, "0", 1);
	return (1);
}

int	ft_puthexupper_fd(unsigned int n, int fd)
{
	unsigned int	copy;
	int				i;
	int				res;

	res = 0;
	if (n == 0)
		return (print_zero(fd));
	copy = reverse (n);
	i = digits_n(n);
	while (copy != 0)
	{
		ft_puthex_upper(copy % 16);
		copy = copy / 16;
		i--;
		res++;
	}
	while (i > 0)
	{
		ft_puthex_upper(0);
		res++;
		i--;
	}
	return (res);
}
