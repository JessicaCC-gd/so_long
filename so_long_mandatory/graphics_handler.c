/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:03:47 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 13:00:12 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	count_map_lines(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	image_assign(t_vars *v, int i, int h, int w)
{
	int	j;

	j = 0;
	while (v->map[i][j])
	{
		if (v->map[i][j] == '1')
			mlx_put_image_to_window(v->mlx, v->win, v->img.wall, w, h);
		if (v->map[i][j] == '0')
			mlx_put_image_to_window(v->mlx, v->win, v->img.floor, w, h);
		if (v->map[i][j] == 'P')
		{
			mlx_put_image_to_window(v->mlx, v->win, v->img.rb, w, h);
			v->player.pixel_width = w;
			v->player.pixel_height = h;
		}
		if (v->map[i][j] == 'C')
			mlx_put_image_to_window(v->mlx, v->win, v->img.colectible, w, h);
		if (v->map[i][j] == 'E')
			mlx_put_image_to_window(v->mlx, v->win, v->img.finish, w, h);
		w += 64;
		j++;
	}
}

void	draw_map(t_vars *v)
{
	int	i;
	int	height;
	int	width;

	i = 0;
	height = 0;
	width = 0;
	while (v->map[i])
	{
		image_assign(v, i, height, width);
		height += 64;
		i++;
	}
}
