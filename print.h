#ifndef PRINT_H
# define PRINT_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
int	ft_printf(char const *str, ...);
static int	ft_putnbr_base(unsigned long nbr, char *base);
int	tipe_detector(char type, va_list arg);
static int	ft_hexdes_arg(va_list arg, char type);
static void	ft_putnbr_fd(long n, int fd);
static int	ft_putnbr_arg(va_list arg, char type);
int	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
char	*ft_itoa(int n);
static int	size(int n);
int     ft_putstr_fd(char *s, int fd);
#endif
