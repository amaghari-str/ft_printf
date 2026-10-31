
#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		ret1;
	int		ret2;
	char	*str;

	str = "Hello, 42!";
	printf("===== TEST CHAR =====\n");
	printf("Original:   %c\n", 'A');
	ft_printf("ft_printf:  %c\n", 'A');

	printf("\n===== TEST STRING =====\n");
	printf("Original:   %s\n", str);
	ft_printf("ft_printf:  %s\n", str);

	printf("\n===== TEST POINTER =====\n");
	printf("Original:   %p\n", str);
	ft_printf("ft_printf:  %p\n", str);
	printf("NULL:       %p\n", (void *)0);
	ft_printf("NULL:       %p\n", (void *)0);

	printf("\n===== TEST DECIMAL / INTEGER =====\n");
	printf("Original:   %d %i %d\n", 42, -42, INT_MIN);
	ft_printf("ft_printf:  %d %i %d\n", 42, -42, INT_MIN);

	printf("\n===== TEST UNSIGNED =====\n");
	printf("Original:   %u %u\n", 42u, UINT_MAX);
	ft_printf("ft_printf:  %u %u\n", 42u, UINT_MAX);

	printf("\n===== TEST HEXADECIMAL =====\n");
	printf("Original:   %x %X\n", 255, 255);
	ft_printf("ft_printf:  %x %X\n", 255, 255);

	printf("\n===== TEST PERCENT =====\n");
	printf("Original:   %% %%\n");
	ft_printf("ft_printf:  %% %%\n");

	printf("\n===== TEST RETURN VALUE =====\n");
	ret1 = printf("Original:   %d %s %x\n", 42, "test", 255);
	ret2 = ft_printf("ft_printf:  %d %s %x\n", 42, "test", 255);
	printf("printf return:    %d\n", ret1);
	printf("ft_printf return: %d\n", ret2);

	printf("\n===== TEST EMPTY STRING =====\n");
	printf("Original:   %s\n", "");
	ft_printf("ft_printf:  %s\n", "");

	printf("\n===== TEST ZERO =====\n");
	printf("Original:   %d %u %x %X\n", 0, 0u, 0, 0);
	ft_printf("ft_printf:  %d %u %x %X\n", 0, 0u, 0, 0);

	return (0);
}

