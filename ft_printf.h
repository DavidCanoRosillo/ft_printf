#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
int	ft_printf(const char *str, ...);
int	ft_puthexlower_fd(unsigned int n, int fd);
int	ft_puthexupper_fd(unsigned int n, int fd);
int	ft_putnbr_fd(int n, int fd);
int	ft_category_u_fd(unsigned int n, int fd);
int	ft_category_p_fd(unsigned long n, int fd);
#endif
