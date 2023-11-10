/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:37:06 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/01 16:54:03 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	i;
	size_t	tot;

	tot = nmemb * size;
	p = malloc((tot) * sizeof(char));
	if (p == 0)
		return (0);
	i = 0;
	while (i < tot)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
