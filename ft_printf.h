#ifndef PRINT_H
# define PRINT_H

#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int	ft_printf(char const *str, ...);
int	tipe_detector(char type, va_list arg);
int	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(char *str);
char	*ft_itoa(long n);
int     ft_putstr_fd(char *s, int fd);

#endif
