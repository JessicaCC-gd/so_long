/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:58:38 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 13:36:43 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	assign_textures(t_vars *v)
{
	int	s;

	v->img.floor = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/Floor.xpm", &s, &s);
	v->img.wall = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/wall5.xpm", &s, &s);
	v->img.rb = mlx_xpm_file_to_image(v->mlx,
			"./Textures/roomba/u_f01.xpm", &s, &s);
	v->img.finish = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/Base_f01.xpm", &s, &s);
	v->img.colectible = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/dust3.xpm", &s, &s);
}
