/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:39:19 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/20 22:48:37 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	find_conversion(char c, va_list args);
int	ft_printf(const char *str, ...);
int	print_char(const char c);
int	print_hexa(unsigned long long n, char c);
int	print_int(int n);
int	print_pointer(unsigned long long n);
int	print_string(const char *str);
int	print_unsigned(unsigned int n);

#endif
