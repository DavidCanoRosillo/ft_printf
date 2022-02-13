/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcano-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 13:32:28 by dcano-ro          #+#    #+#             */
/*   Updated: 2022/02/13 13:33:05 by dcano-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_puthexlower_fd(unsigned int n, int fd);
int	ft_puthexupper_fd(unsigned int n, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_category_p_fd(unsigned long n, int fd);
int	ft_category_u_fd(unsigned int n, int fd);
int	category_x(unsigned int n);
int	category_x_uppercase(unsigned int n);
int	category_u(unsigned int n, int fd);
int	category_p(unsigned long n);
int	category_s(char *str);
int	category_null(void);
int	category_c(char c);
int	category_i(int n);
#endif
