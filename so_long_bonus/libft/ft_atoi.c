/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:35:13 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/01 16:54:19 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	number(char const *str, int i, int minuses)
{
	int	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (minuses == 1)
		return (-num);
	return (num);
}

int	ft_atoi(char const *str)
{
	int	i;
	int	pluses;
	int	minuses;

	i = 0;
	minuses = 0;
	pluses = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '+')
			pluses++;
		else
			minuses++;
		if ((minuses >= 1 && pluses >= 1) || minuses > 1 || pluses > 1)
			return (0);
		i++;
	}
	return (number(str, i, minuses));
}
