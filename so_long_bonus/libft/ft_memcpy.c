/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:14:52 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/01 16:55:54 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	size_t	i;
	char	*p_dest;
	char	*p_src;

	i = 0;
	if (src == 0 && dest == 0)
		return (0);
	p_src = (char *) src;
	p_dest = (char *) dest;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return ((void *)p_dest);
}
