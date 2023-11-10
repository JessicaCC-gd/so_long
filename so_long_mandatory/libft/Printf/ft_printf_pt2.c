/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pt2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:29:32 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/20 22:53:39 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include "ft_printf.h"

static int	hexa_len(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	print_hexa(unsigned long long n, char c)
{
	if (n >= 16)
	{
		print_hexa(n / 16, c);
		print_hexa(n % 16, c);
	}
	else
	{
		if (n > 9)
		{
			if (c == 'x')
				print_char((n % 10) + 'a');
			else
				print_char((n % 10) + 'A');
		}
		else
			print_char(n + '0');
	}
	return (hexa_len(n));
}

int	print_pointer(unsigned long long n)
{
	if (n == 0)
		return (print_string("(nil)"));
	print_string("0x");
	print_hexa(n, 'x');
	return (hexa_len(n) + 2);
}
