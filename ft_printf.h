/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cavan-vl <cavan-vl@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/21 13:50:37 by cavan-vl      #+#    #+#                 */
/*   Updated: 2024/01/21 15:01:16 by cavan-vl      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

int	print_c(char c);
int	print_s(char *str);
int	print_nbr(int n, int base, bool unsign);
int	conversion(const char *str, va_list args);
int	ft_printf(const char *str, ...);

#endif