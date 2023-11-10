/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_pt2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:25:26 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 12:56:37 by jecarval         ###   ########.fr       */
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

void	finish_check(t_vars *v)
{
	if (v->new_tile == 'E'
		&& v->counters.ccounter == v->counters.collectibles)
		finish_game(v);
}
