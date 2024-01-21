/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/21 14:23:57 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/21 15:09:10 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n, int base, bool unsign)
{
	char		c;
	long int	ln;
	int			len;

	ln = (long int)n;
	len = 0;
	if (unsign == true)
		n = (unsigned)n;
	if (ln < 0 && base <= 10)
	{
		len += write(1, "-", 1);
		ln *= -1;
	}
	if (ln  >= base)
		len += print_nbr(ln / base, base, true);
	len += print_c((ln % base) + '0');
	return (len);
}

int	print_c(char c)
{
	return(write(1, &c, 1));
}

int	print_s(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}