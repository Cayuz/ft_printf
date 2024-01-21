/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/21 11:17:33 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/21 15:08:43 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	conversion(const char *str, va_list args)
{
	if (*str == '%')
		return (print_c('%'));
	if (*str == 'c')
		return (print_c(va_arg(args, int)));
	if (*str == 's')
		return (print_s(va_arg(args, char *)));
	if (*str == 'd' || *str == 'i')
		return (print_nbr(va_arg(args, int), 10, false));
	// if (*str == "p")
		
	if (*str == "u")
		return (print_nbr(va_arg(args, int), 10, true));

	if (*str == "x")
		return (print_nbr(va_arg(args, int), 16, true));	
	if (*str == "X")
		return (print_nbr(va_arg(args, int), 16, true));
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	args;

	va_start(args, *str);
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
	int		num = 5002;
	char	*str = "Hello";
	char	letter = 'g';

	ft_printf("%d\n", (ft_printf("My printf:\na number: %d\na string: %s\na character: %c\n", num, str, letter)));
	ft_printf("\n");
	printf("%d\n", (printf("Og printf:\na number: %d\na string: %s\na character: %c\n", num, str, letter)));
}