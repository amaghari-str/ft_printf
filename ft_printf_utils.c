/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:37:33 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/01 15:55:55 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned int		base_len;
	int					i;

	i = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	if (nbr >= base_len)
		i = ft_putnbr_base(nbr / base_len, base);
	ft_putchar_fd(base[nbr % base_len], 1);
	i++;
	return (i);
}

static void	ft_putnbr_fd(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

static int	ft_putnbr_arg(va_list arg, char type)
{
	unsigned int	j;
	int		i;

	i = 0;
	if (type == 'u')
	{
		j = va_arg(arg, unsigned int);
		if (j > INT_MAX && j <= UINT_MAX)
		{
			ft_putnbr_fd((long)j, 1);
			return (10);
		}
		else
			i = j;
	}
	if (type != 'u')
		i = va_arg(arg, int);
	ft_putnbr_fd(i, 1);
	return (ft_strlen(ft_itoa(i)));
}

static int	ft_hexdes_arg(va_list arg, char type)
{
	int				i;
	unsigned long	p;

	i = 0;
	if (type == 'x')
		i = ft_putnbr_base((unsigned long)va_arg(arg, unsigned int),
				"0123456789abcdef");
	else if (type == 'X')
		i = ft_putnbr_base((unsigned long)va_arg(arg, unsigned int),
				"0123456789ABCDEF");
	else if (type == 'p')
	{
		p = (unsigned long)va_arg(arg, void *);
		if (!p)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		i = ft_putnbr_base(p, "0123456789abcdef");
		i += 2;
	}
	return (i);
}

int	tipe_detector(char type, va_list arg)
{
	char	*p;

	if (type == 'c')
		return (ft_putchar_fd(va_arg(arg, int), 1));
	if (type == 's')
	{
		p = va_arg(arg, char *);
		return (ft_putstr_fd(p, 1));
	}
	if (type == 'd' || type == 'i' || type == 'u')
		return (ft_putnbr_arg(arg, type));
	if (type == 'x' || type == 'X' || type == 'p')
		return (ft_hexdes_arg(arg, type));
	if (type == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
