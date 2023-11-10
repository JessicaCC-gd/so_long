/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:03:47 by jecarval          #+#    #+#             */
/*   Updated: 2023/11/10 19:29:06 by jecarval         ###   ########.fr       */
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

void	draw_ui(t_vars *v)
{
	char	*tmp;

	mlx_put_image_to_window(v->mlx, v->win, v->scoreboard, 5, 5);
	tmp = ft_itoa(v->counters.steps);
	mlx_string_put(v->mlx, v->win, 15, 30, 0xFFFFFF, "Steps: ");
	mlx_string_put(v->mlx, v->win, 55, 30, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(v->counters.ccounter);
	mlx_string_put(v->mlx, v->win, 100, 30, 0xFFFFFF, "Sucked:");
	mlx_string_put(v->mlx, v->win, 145, 30, 0xFFFFFF, tmp);
	free(tmp);
	tmp = ft_itoa(v->counters.collectibles);
	mlx_string_put(v->mlx, v->win, 160, 30, 0xFFFFFF, "out of");
	mlx_string_put(v->mlx, v->win, 205, 30, 0xFFFFFF, tmp);
	free(tmp);
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
		if (v->map[i][j] == 'V')
			mlx_put_image_to_window(v->mlx, v->win, v->img.cat, w, h);
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
	draw_ui(v);
}
