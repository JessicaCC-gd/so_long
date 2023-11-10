/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pt3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:29:32 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/20 23:01:03 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include "ft_printf.h"

int	print_char(const char c)
{
	return (write (1, &c, 1));
}

int	print_string(const char *str)
{
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
		return (write(1, str, ft_strlen(str)));
}

int	print_int(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	len = print_string(num);
	free(num);
	return (len);
}

static int	count_nums(unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

int	print_unsigned(unsigned int n)
{
	char			*str;
	int				size;

	size = count_nums(n);
	str = malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[size--] = 0;
	while (n != 0)
	{
		str[size--] = (n % 10 + 48);
		n = n / 10;
	}
	print_string(str);
	size = ft_strlen(str);
	free(str);
	return (size);
}
