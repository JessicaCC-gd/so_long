/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:33:28 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 14:57:01 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr_mod(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strdup(const char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_len(s);
	str = malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *read_total, char const *read_read)
{
	int		i;
	int		j;
	char	*new_total;

	if (!read_total)
		return (gnl_strdup(read_read));
	if (!read_read)
		return (0);
	new_total = malloc((ft_len(read_total)
				+ ft_len(read_read) + 1) * sizeof(char));
	if (!new_total)
		return (0);
	i = 0;
	while (read_total[i] != 0)
	{
		new_total[i] = read_total[i];
		i++;
	}
	j = 0;
	while (read_read[j] != 0)
		new_total[i++] = read_read[j++];
	new_total[i] = 0;
	free((void *)read_total);
	return (new_total);
}
