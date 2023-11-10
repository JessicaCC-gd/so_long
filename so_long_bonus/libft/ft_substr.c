/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:39:05 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/01 16:58:57 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= (unsigned int)ft_strlen(s))
	{
		str = malloc(1 * sizeof(char));
		if (str == 0)
			return (0);
		str[0] = 0;
		return (str);
	}
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len && s)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
