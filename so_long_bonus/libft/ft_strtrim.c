/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:21:08 by jecarval          #+#    #+#             */
/*   Updated: 2023/01/11 18:09:49 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, const char *set)
{
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	if (*set == 0 || *s1 == 0)
		return ((char *)s1);
	i = 0;
	while (s1[i] && ft_strchr((char *)set, s1[i]) != 0)
		i++;
	j = ft_strlen(s1) - 1;
	while (j > i && ft_strchr((char *)set, s1[j]) != 0)
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
