/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:12:41 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 13:24:14 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	walls_test(t_vars *v)
{
	int	i;
	int	last_line;
	int	last_char;

	i = 0;
	last_line = count_map_lines(v->map) - 1;
	last_char = ft_strlen(v->map[i]) - 1;
	while (i < last_char)
	{
		if ((v->map[0][i] != '1' && v->map[0][i] != '\0')
			|| (v->map[last_line][i] != '1'
			&& v->map[last_line][i] != '\0'))
			invalid_map(v);
		i++;
	}
	i = 1;
	while (i < last_line)
	{
		if ((v->map[i][0] != '1' || v->map[i][last_char - 1] != '1'))
			invalid_map(v);
		i++;
	}
}

void	length_test(t_vars *v)
{
	int	i;
	int	len_0;
	int	nlines;

	i = 1;
	nlines = count_map_lines(v->map);
	len_0 = ft_strlen(v->map[0]);
	if (ft_strlen(v->map[nlines - 1]) != (len_0 - 1))
		invalid_map(v);
	while (i < nlines - 1)
	{
		if (len_0 != ft_strlen(v->map[i]))
			invalid_map(v);
		i++;
	}
}

void	map_counter(t_vars *v, int *pecv, int *p_coord, int i)
{
	int	j;

	j = 1;
	while (v->map[i][j + 1])
	{
		if (v->map[i][j] != '1' && v->map[i][j] != '0'
		&& v->map[i][j] != 'P' && v->map[i][j] != 'C'
		&& v->map[i][j] != 'E')
			invalid_map(v);
		if (v->map[i][j] == 'P')
		{
			pecv[0]++;
			p_coord[0] = i;
			p_coord[1] = j;
		}
		if (v->map[i][j] == 'C')
			pecv[2]++;
		if (v->map[i][j] == 'E')
			pecv[1]++;
		j++;
	}
}

void	map_tester(t_vars *v)
{
	int	pecv[3];
	int	p_coord[2];
	int	i;

	pecv[0] = 0;
	pecv[1] = 0;
	pecv[2] = 0;
	length_test(v);
	walls_test(v);
	i = 1;
	while (v->map[i])
	{
		map_counter(v, pecv, p_coord, i);
		i++;
	}
	if (pecv[2] < 1 || pecv[0] != 1 || pecv[1] != 1)
		invalid_map(v);
	v->counters.collectibles = pecv[2];
	path_test(pecv, p_coord, v);
}
