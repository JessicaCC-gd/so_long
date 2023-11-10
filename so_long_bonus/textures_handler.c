/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:58:38 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 15:24:02 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	textures_roomba_vertical(t_vars *v)
{
	v->r_spt.u = malloc (9 * sizeof(char *));
	v->r_spt.u[0] = "./Textures/roomba/u_f01.xpm";
	v->r_spt.u[1] = "./Textures/roomba/u_f02.xpm";
	v->r_spt.u[2] = "./Textures/roomba/u_f01.xpm";
	v->r_spt.u[3] = "./Textures/roomba/u_f04.xpm";
	v->r_spt.u[4] = "./Textures/roomba/u_f01.xpm";
	v->r_spt.u[5] = "./Textures/roomba/u_f02.xpm";
	v->r_spt.u[6] = "./Textures/roomba/u_f03.xpm";
	v->r_spt.u[7] = "./Textures/roomba/u_f02.xpm";
	v->r_spt.u[8] = NULL;
	v->r_spt.d = malloc (9 * sizeof(char *));
	v->r_spt.d[0] = "./Textures/roomba/d_f01.xpm";
	v->r_spt.d[1] = "./Textures/roomba/d_f02.xpm";
	v->r_spt.d[2] = "./Textures/roomba/d_f01.xpm";
	v->r_spt.d[3] = "./Textures/roomba/d_f04.xpm";
	v->r_spt.d[4] = "./Textures/roomba/d_f01.xpm";
	v->r_spt.d[5] = "./Textures/roomba/d_f02.xpm";
	v->r_spt.d[6] = "./Textures/roomba/d_f03.xpm";
	v->r_spt.d[7] = "./Textures/roomba/d_f02.xpm";
	v->r_spt.d[8] = NULL;
}

void	textures_roomba_horizontal(t_vars *v)
{
	v->r_spt.r = malloc (9 * sizeof(char *));
	v->r_spt.r[0] = "./Textures/roomba/r_f01.xpm";
	v->r_spt.r[1] = "./Textures/roomba/r_f02.xpm";
	v->r_spt.r[2] = "./Textures/roomba/r_f01.xpm";
	v->r_spt.r[3] = "./Textures/roomba/r_f04.xpm";
	v->r_spt.r[4] = "./Textures/roomba/r_f01.xpm";
	v->r_spt.r[5] = "./Textures/roomba/r_f02.xpm";
	v->r_spt.r[6] = "./Textures/roomba/r_f03.xpm";
	v->r_spt.r[7] = "./Textures/roomba/r_f02.xpm";
	v->r_spt.r[8] = NULL;
	v->r_spt.l = malloc (9 * sizeof(char *));
	v->r_spt.l[0] = "./Textures/roomba/l_f01.xpm";
	v->r_spt.l[1] = "./Textures/roomba/l_f02.xpm";
	v->r_spt.l[2] = "./Textures/roomba/l_f01.xpm";
	v->r_spt.l[3] = "./Textures/roomba/l_f04.xpm";
	v->r_spt.l[4] = "./Textures/roomba/l_f01.xpm";
	v->r_spt.l[5] = "./Textures/roomba/l_f02.xpm";
	v->r_spt.l[6] = "./Textures/roomba/l_f03.xpm";
	v->r_spt.l[7] = "./Textures/roomba/l_f02.xpm";
	v->r_spt.l[8] = NULL;
}

void	assign_anim(t_vars *v)
{
	textures_roomba_vertical(v);
	textures_roomba_horizontal(v);
	v->b_spt.f01 = "./Textures/map/Base_f01.xpm";
	v->b_spt.f02 = "./Textures/map/Base_f02.xpm";
	v->c_spt.frames = malloc (11 * sizeof(char *));
	v->c_spt.frames[0] = "./Textures/cat/cat_f00.xpm";
	v->c_spt.frames[1] = "./Textures/cat/cat_f01.xpm";
	v->c_spt.frames[2] = "./Textures/cat/cat_f00.xpm";
	v->c_spt.frames[3] = "./Textures/cat/cat_f02.xpm";
	v->c_spt.frames[4] = "./Textures/cat/cat_f00.xpm";
	v->c_spt.frames[5] = "./Textures/cat/cat_f01.xpm";
	v->c_spt.frames[6] = "./Textures/cat/cat_f03.xpm";
	v->c_spt.frames[7] = "./Textures/cat/cat_f01.xpm";
}

void	assign_textures(t_vars *v)
{
	int	s;

	assign_anim(v);
	v->scoreboard = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/scoreboard.xpm", &s, &s);
	v->img.floor = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/Floor.xpm", &s, &s);
	v->img.wall = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/wall5.xpm", &s, &s);
	v->img.rb = mlx_xpm_file_to_image(v->mlx,
			"./Textures/roomba/u_f01.xpm", &s, &s);
	v->img.finish = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/Base_f01.xpm", &s, &s);
	v->img.cat = mlx_xpm_file_to_image(v->mlx,
			"./Textures/cat/cat_f01.xpm", &s, &s);
	v->img.colectible = mlx_xpm_file_to_image(v->mlx,
			"./Textures/map/dust3.xpm", &s, &s);
}
