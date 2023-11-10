/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:03:13 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 17:34:05 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	invalid_map(t_vars *v)
{
	int	i;

	i = -1;
	while (v->map[++i])
		free(v->map[i]);
	free(v->map);
	ft_printf("Error\n Invalid map\n");
	exit (0);
}

char	**replicate_map(t_vars *v)
{	
	int		i;
	char	**map_temp;

	i = 0;
	map_temp = malloc((count_map_lines(v->map) + 1) * sizeof(char *));
	if (!map_temp)
		return (0);
	while (v->map[i])
	{
		map_temp[i] = ft_strdup(v->map[i]);
		i++;
	}
	map_temp[i] = 0;
	return (map_temp);
}

char	**read_map(int map_file, t_vars *v)
{
	int		i;
	char	*tmp;

	i = 0;
	v->map = ft_calloc(150, sizeof(char *));
	while (i < 150)
	{
		tmp = get_next_line(map_file);
		if (i == 0 && !tmp)
			invalid_map(v);
		if (!tmp)
			break ;
		v->map[i++] = tmp;
	}
	v->map[i] = 0;
	map_tester(v);
	return (v->map);
}

int	no_map(void)
{
	ft_printf("Error\n	No loaded map!\n");
	exit (0);
}
