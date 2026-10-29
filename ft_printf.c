/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 18:22:13 by amaghari          #+#    #+#             */
/*   Updated: 2026/10/29 18:28:39 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	ft_printf(char const *str, ...)
{
	va_list	vargs;
	int		len;
	int		check;

	va_start(vargs, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			check = tipe_detector(*(++str), vargs);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, str, 1) == -1)
				return (-1);
			len++;
		}
		str++;
	}
	va_end(vargs);
	return (len);
}
