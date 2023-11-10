/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:33:25 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/24 18:23:17 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	find_cat(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (v->map[i])
	{
		j = 0;
		while (v->map[i][j])
		{
			if (v->map[i][j] == 'V')
			{
				v->cat.map_x = j;
				v->cat.map_y = i;
			}
			j++;
		}
		i++;
	}
}

void	print_map(t_vars *v)
{
	int	i;

	i = -1;
	while (v->map[++i])
		printf("%s\n", v->map[i]);
}

void	check_for_player(t_vars *v, int y, int x)
{
	if (v->map[y][x] == 'P')
	{
		ft_printf("The cat got on top of you and broke you. RIP!\n");
		kill_game(v);
	}
}

int	patrol_check(t_vars *v, int cat_x, int cat_y)
{
	int	counter;

	counter = 0;
	if (v->map[v->cat.map_y][v->cat.map_x] == '1'
		|| v->map[v->cat.map_y][v->cat.map_x] == 'E'
		|| v->map[v->cat.map_y][v->cat.map_x] == 'C')
	{
		v->cat.map_x = cat_x;
		v->cat.map_y = cat_y;
		return (1);
	}
	if (v->map[v->cat.map_y][v->cat.map_x] == 'P')
	{
		v->map[v->cat.map_y][v->cat.map_x] = 'V';
		draw_map(v);
		while (counter != 500000)
			counter++;
		ft_printf("The cat got on top of you and broke you. RIP!\n");
		kill_game(v);
	}
	return (0);
}

void	move_patrol(t_vars *v, int i)
{
	int	cat_x;
	int	cat_y;

	find_cat(v);
	cat_x = v->cat.map_x;
	cat_y = v->cat.map_y;
	if (i == 0)
		v->cat.map_y--;
	if (i == 1)
		v->cat.map_y++;
	if (i == 2)
		v->cat.map_x--;
	if (i == 3)
		v->cat.map_x++;
	if (patrol_check(v, cat_x, cat_y) == 1)
		return ;
	v->map[v->cat.map_y][v->cat.map_x] = 'V';
	v->map[cat_y][cat_x] = '0';
}
