/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:25:26 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 15:14:48 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_vars	*find_player(t_vars *v)
{
	int	i;
	int	j;

	i = 0;
	while (v->map[i])
	{
		j = 0;
		while (v->map[i][j])
		{
			if (v->map[i][j] == 'P')
			{
				v->player.map_x = j;
				v->player.map_y = i;
				return (v);
			}
			j++;
		}
		i++;
	}
	return (v);
}

int	patrol(t_vars *v)
{
	static int	counter;
	int			i;

	counter++;
	if (counter == 200)
	{
		i = (rand() % 4);
		move_patrol(v, i);
		counter = 0;
	}
	return (0);
}

void	finish_check(t_vars *v)
{
	if (v->new_tile == 'V')
	{
		ft_printf("The cat got on top of you and broke you. RIP!\n");
		kill_game(v);
	}
	if (v->new_tile == 'E'
		&& v->counters.ccounter == v->counters.collectibles)
		finish_game(v);
}
