/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:00:24 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/21 18:20:32 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h" 

static void	ft_puthex_lower(int nbr)
{
	char	lower_hex[6];
	char	c;

	lower_hex[0] = 'a';
	lower_hex[1] = 'b';
	lower_hex[2] = 'c';
	lower_hex[3] = 'd';
	lower_hex[4] = 'e';
	lower_hex[5] = 'f';
	if (nbr >= 10)
		write(1, lower_hex + nbr - 10, 1);
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

static	int	digits_n(unsigned int n)
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

int	print_zero(int fd)
{
	write(fd, "0", 1);
	return (1);
}

int	ft_puthexlower_fd(unsigned int n, int fd)
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
		ft_puthex_lower(copy % 16);
		copy = copy / 16;
		i--;
		res++;
	}	
	while (i > 0)
	{
		ft_puthex_lower(0);
		res++;
		i--;
	}
	return (res);
}
