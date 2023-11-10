/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:58:26 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 15:14:43 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	anim_base(t_vars *v, int i, int s)
{
	mlx_destroy_image(v->mlx, v->img.finish);
	if (i % 3 == 0)
		v->img.finish = mlx_xpm_file_to_image(v->mlx,
				v->b_spt.f01, &s, &s);
	else
		v->img.finish = mlx_xpm_file_to_image(v->mlx,
				v->b_spt.f02, &s, &s);
}

void	anim_sprites(t_vars *v, int i, int s)
{
	mlx_destroy_image(v->mlx, v->img.rb);
	if (v->last_move == 'u')
		v->img.rb = mlx_xpm_file_to_image(v->mlx,
				v->r_spt.u[i], &s, &s);
	else
	{
		if (v->last_move == 'd')
			v->img.rb = mlx_xpm_file_to_image(v->mlx, v->r_spt.d[i], &s, &s);
		else
		{
			if (v->last_move == 'r')
				v->img.rb = mlx_xpm_file_to_image(v->mlx,
						v->r_spt.r[i], &s, &s);
			else
				v->img.rb = mlx_xpm_file_to_image(v->mlx,
						v->r_spt.l[i], &s, &s);
		}
	}
	mlx_destroy_image(v->mlx, v->img.cat);
	v->img.cat = mlx_xpm_file_to_image(v->mlx,
			v->c_spt.frames[i % 2], &s, &s);
}

int	animate(t_vars *v)
{
	static int	i;
	int			s;
	static int	counter;

	s = 0;
	if (i < 0 || i > 7)
		i = 0;
	counter++;
	anim_sprites(v, i, s);
	anim_base(v, i, s);
	draw_map(v);
	if (v->cat.counter > 0)
		patrol(v);
	if (counter == 100)
	{
		counter = 0;
		i++;
	}
	return (0);
}
