/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:59:00 by jecarval          #+#    #+#             */
/*   Updated: 2022/11/24 19:42:59 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*temp;

	if (!s || !f)
		return (0);
	i = 0;
	temp = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (temp == 0)
		return (0);
	while (s[i] != 0)
	{
		temp[i] = f(i, s[i]);
		i++;
	}
	temp[i] = 0;
	return (temp);
}
