/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_categories1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:44:26 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/13 13:28:33 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	category_s(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

int	category_null(void)
{
	write(1, "(null)", 6);
	return (6);
}

int	category_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	category_i(int n)
{
	return (ft_putnbr_fd(n, 1));
}
