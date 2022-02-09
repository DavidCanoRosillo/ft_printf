/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:32:43 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/01/31 18:11:32 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int category_s(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

static int	category_null()
{
	write(1, "(null)", 6);
	return (6);
}

static int category_c(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	category_i(int n)
{
	return (ft_putnbr_fd(n, 1));
}

static int	category_x(unsigned int n)
{
	return (ft_puthexlower_fd(n, 1));
}

static int	category_X(unsigned int n)
{
	return (ft_puthexupper_fd(n, 1));
}

static int	category_u(unsigned int n)
{
	return (ft_category_u_fd(n, 1));
}

static int category_p(unsigned long n)
{
	write(1, "0x", 2);
	if (n == 0)
	{
		write(1, "0", 1);
		return (3);
	}
	return (2 + ft_category_p_fd(n, 1));
}

static int	print_arg(const char *str, va_list ptr)
{
	void *arg;
	if (*str == '%')
		return (category_c('%'));
	arg = va_arg(ptr, char*);
	if (arg == NULL && *str == 's')
		return (category_null());
	if (*str == 's')	
		return category_s((char *) arg);
	if (*str == 'c')
		return category_c((char) arg);
	if (*str == 'i' || *str == 'd')
		return (category_i((int) arg));
	if (*str == 'x')
		return (category_x((unsigned int) arg));
	if (*str == 'X')
		return (category_X((unsigned int) arg));
	if (*str == 'u')
		return (category_u((unsigned int) arg));
	if (*str == 'p')
		return (category_p((unsigned long) arg));
	return (-1);
	/*
	if (*str == '%')
		write(1, "%", 1);
	if (*str == 'i')
		ft_putnbr_fd(va_arg(ptr, int), 1);
	if (*str == 'x')
		ft_puthexlower_fd(va_arg(ptr, unsigned int), 1);
	*/
}

int	ft_printf(const char *str, ...)
{
	int i;
	va_list ptr;
	int result;

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

/*
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i = 5;
	//printf("%d", sizeof(void*));
	printf("their:%d\n", printf(" %p ", (void *)0));
	printf("mine:%d\n", ft_printf(" %p ",(void *) 0));
}
*/
