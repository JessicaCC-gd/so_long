/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pt1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:29:32 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/20 21:40:17 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

int	find_conversion(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_string(va_arg(args, char *)));
	if (c == 'p')
		return (print_pointer(va_arg(args, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	if (c == 'u')
		return (print_unsigned(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
		return (print_hexa(va_arg(args, unsigned int), c));
	if (c == '%')
		return (write (1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += find_conversion(str[i + 1], args);
			i++;
		}
		else
			len += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/* 
int main ()
{
	int	a = 13;
	char b = '1';
	char *c = "hfghsdfh";
	unsigned int d = 1254323455;

	int i = printf("batata %% %d %c %s %u %p %x %X\n", a, b, c, d, &c, d, d);
	int j = ft_printf("batata %% %d %c %s %u %p %x %X\n", a, b, c, d, &c, d, d);
	
	printf ("%d %d\n", i, j);
	return (0);
} */
