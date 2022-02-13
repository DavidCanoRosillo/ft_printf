/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_categories2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:36:37 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/13 13:28:49 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	category_x(unsigned int n)
{
	return (ft_puthexlower_fd(n, 1));
}

int	category_x_uppercase(unsigned int n)
{
	return (ft_puthexupper_fd(n, 1));
}

int	category_p(unsigned long n)
{
	write(1, "0x", 2);
	if (n == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	return (2 + ft_category_p_fd(n, 1));
}
