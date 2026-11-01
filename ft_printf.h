/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghari <amaghari@student.42belgium.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:05:41 by amaghari          #+#    #+#             */
/*   Updated: 2026/11/01 15:42:25 by amaghari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(char *str);
int		ft_printf(char const *str, ...);
int		tipe_detector(char type, va_list arg);
int		ft_putchar_fd(char c, int fd);
char	*ft_itoa(long n);
int		ft_putstr_fd(char *s, int fd);

#endif
