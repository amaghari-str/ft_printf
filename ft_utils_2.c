/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:29:04 by amaghari          #+#    #+#             */
/*   Updated: 2026/10/29 16:32:24 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	size(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		n++;
	if (n < 0)
	{
		n *= -1;
		size ++;
	}
	while (n >= 10)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	char			*res;
	int				i;

	i = size(n);
	res = malloc (i + 1);
	if (n == 0)
	{
		res[0] = '0';
		num = 0;
	}
	else if (n < 0)
	{
		res[0] = '-';
		num = -(unsigned int)n;
	}
	else
		num = n;
	res[i--] = '\0';
	while (num > 0)
	{
		res[i--] = '0' + (num % 10);
		num /= 10;
	}
	return (res);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
