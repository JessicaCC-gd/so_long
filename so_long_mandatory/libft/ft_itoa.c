/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:46:09 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/01 16:55:17 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count(int n)
{
	int		counter;

	counter = 0;
	if (n <= 0)
	{
		counter++;
		n = -n;
	}
	while (n != 0)
	{
		counter++;
		n = n / 10;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		sign;

	sign = 1;
	size = count(n);
	str = malloc((size + 1) * sizeof(char));
	if (str == 0)
		return (0);
	if (n < 0)
	{	
		str[0] = '-';
		sign = -1;
	}
	else if (n == 0)
		str[0] = '0';
	str[size--] = 0;
	while (n != 0)
	{
		str[size--] = ((n % 10) * sign + 48);
		n = n / 10;
	}
	return (str);
}
