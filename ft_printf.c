/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:32:43 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/21 18:19:35 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_arg(const char *str, va_list ptr)
{
	void	*arg;

	if (*str == '%')
		return (category_c('%'));
	arg = va_arg(ptr, char *);
	if (arg == NULL && *str == 's')
		return (category_null());
	if (*str == 's')
		return (category_s((char *) arg));
	if (*str == 'c')
		return (category_c((char) arg));
	if (*str == 'i' || *str == 'd')
		return (category_i((int) arg));
	if (*str == 'x')
		return (category_x((unsigned int) arg));
	if (*str == 'X')
		return (category_x_uppercase((unsigned int) arg));
	if (*str == 'u')
		return (category_u((unsigned int) arg, 1));
	if (*str == 'p')
		return (category_p((unsigned long) arg));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;
	int		result;

	i = 0;
	va_start(ptr, str);
	result = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i])
				result += print_arg(str + i, ptr);
		}
		else
		{
			write(1, str + i, 1);
			result++;
		}
		i++;
	}
	va_end(ptr);
	return (result);
}
