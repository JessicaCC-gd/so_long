/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:48:47 by jecarval          #+#    #+#             */
/*   Updated: 2022/12/01 16:59:42 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_strs(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			++j;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		end;
	char	**strs;

	if (!s)
		return (0);
	i = 0;
	start = 0;
	strs = malloc((count_strs(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	while (i < count_strs(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != 0)
			end++;
		strs[i] = ft_substr(s, start, end - start);
		start = end;
		i++;
	}
	strs[i] = 0;
	return (strs);
}
