/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/21 11:17:33 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/22 20:55:31 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *str, va_list args)
{
	int	len;

	len = 0;
	if (*str == '%')
		return (len + print_c('%'));
	if (*str == 'c')
		return (len + print_c(va_arg(args, int)));
	if (*str == 's')
		return (len + print_s(va_arg(args, char *)));
	if (*str == 'd' || *str == 'i')
		return (len + print_int(va_arg(args, int), *str, 10));
	if (*str == 'u')
		return (len + print_int(va_arg(args, int), *str, 10));
	if (*str == 'p')
		return (len + print_p(va_arg(args, void*)));
	if (*str == 'x')
		return (len + print_int(va_arg(args, int), *str, 16));
	if (*str == 'X')
		return (len + print_int(va_arg(args, int), *str, 16));
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	if (!str)
		return (print_s("(null)"));
	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%' && *(str + 1))
		{
			str++;
			len += conversion(str, args);
		}
		else
			len += print_c(*str);
		str++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	// int		num = 5;
	// char	*str = "Hello";
	// char	letter = 'g';

	// int	hex = 654645;
	// int	hexup = 89879547;
	// int test = 46;

	printf("chars: %d\n", ft_printf(" %x ", -100));
	printf("chars: %d\n", printf(" %x ", -100));
	// ft_printf("%x\n%X\n", hex, hexup);
	// ft_printf("total characters printed: %d\n", (ft_printf("My printf:\na number: %d\na string: %s\na character: %c\n", num, str, letter)));
	// ft_printf("\n");
	// printf("%x\n%X\n", hex, hexup);
	// printf("total characters printed: %d\n", (printf("Og printf:\na number: %d\na string: %s\na character: %c\n", num, str, letter)));
}