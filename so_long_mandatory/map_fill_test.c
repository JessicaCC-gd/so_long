/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:03:10 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 13:20:43 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	fill(int x, int y, char **map_temp, int *tpec)
{
	if (map_temp[y][x] != '1' && map_temp[y][x] != 'A')
	{
		if (map_temp[y][x] == 'E')
			tpec[1]++;
		if (map_temp[y][x] == 'P')
			tpec[0]++;
		if (map_temp[y][x] == 'C')
			tpec[2]++;
		map_temp[y][x] = 'A';
		fill(x + 1, y, map_temp, tpec);
		fill(x, y + 1, map_temp, tpec);
		fill(x - 1, y, map_temp, tpec);
		fill(x, y - 1, map_temp, tpec);
	}
}

void	path_test(int *pec, int *p_coord, t_vars *v)
{
	char	**map_temp;
	int		x;
	int		y;
	int		i;
	int		tpec[3];

	tpec[0] = 0;
	tpec[1] = 0;
	tpec[2] = 0;
	map_temp = replicate_map(v);
	y = p_coord[0];
	x = p_coord[1];
	fill(x, y, map_temp, tpec);
	i = -1;
	while (v->map[++i])
		free(map_temp[i]);
	free(map_temp);
	if (tpec[0] != pec[0] || tpec[1] != pec[1] || tpec[2] != pec[2])
		invalid_map(v);
}
