/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_pt1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:03:33 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 12:13:10 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_up(t_vars *v)
{
	v->last_move = 'u';
	if (v->map[v->player.map_y - 1][v->player.map_x] == '1')
		return ;
	if (v->map[v->player.map_y - 1][v->player.map_x] == 'C')
		v->counters.ccounter++;
	if (v->prev_tile == 'E')
		v->map[v->player.map_y][v->player.map_x] = 'E';
	else
		v->map[v->player.map_y][v->player.map_x] = '0';
	v->new_tile = v->map[--v->player.map_y][v->player.map_x];
	v->counters.steps++;
	ft_printf("Steps: %d\n", v->counters.steps);
}

void	move_down(t_vars *v)
{
	v->last_move = 'd';
	if (v->map[v->player.map_y + 1][v->player.map_x] == '1')
		return ;
	if (v->map[v->player.map_y + 1][v->player.map_x] == 'C')
		v->counters.ccounter++;
	if (v->prev_tile == 'E')
		v->map[v->player.map_y][v->player.map_x] = 'E';
	else
		v->map[v->player.map_y][v->player.map_x] = '0';
	v->new_tile = v->map[++v->player.map_y][v->player.map_x];
	v->counters.steps++;
	ft_printf("Steps: %d\n", v->counters.steps);
}

void	move_left(t_vars *v)
{
	v->last_move = 'l';
	if (v->map[v->player.map_y][v->player.map_x - 1] == '1')
		return ;
	if (v->map[v->player.map_y][v->player.map_x - 1] == 'C')
		v->counters.ccounter++;
	if (v->prev_tile == 'E')
		v->map[v->player.map_y][v->player.map_x] = 'E';
	else
		v->map[v->player.map_y][v->player.map_x] = '0';
	v->new_tile = v->map[v->player.map_y][--v->player.map_x];
	v->counters.steps++;
	ft_printf("Steps: %d\n", v->counters.steps);
}

void	move_right(t_vars *v)
{
	v->last_move = 'r';
	if (v->map[v->player.map_y][v->player.map_x + 1] == '1')
		return ;
	if (v->map[v->player.map_y][v->player.map_x + 1] == 'C')
		v->counters.ccounter++;
	if (v->prev_tile == 'E')
		v->map[v->player.map_y][v->player.map_x] = 'E';
	else
		v->map[v->player.map_y][v->player.map_x] = '0';
	v->new_tile = v->map[v->player.map_y][++v->player.map_x];
	v->counters.steps++;
	ft_printf("Steps: %d\n", v->counters.steps);
}

void	movement_handler(int keycode, t_vars *v)
{
	v->prev_tile = v->new_tile;
	v = find_player(v);
	if (keycode == 119)
		move_up(v);
	if (keycode == 115)
		move_down(v);
	if (keycode == 97)
		move_left(v);
	if (keycode == 100)
		move_right(v);
	v->map[v->player.map_y][v->player.map_x] = 'P';
	draw_map(v);
	finish_check(v);
}
