/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:11:39 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/31 00:11:43 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallhit(t_all *all)
{
	while (all->parsvars.worldmap[(int)all->calcpxls.mapx]
			[(int)all->calcpxls.mapy] != 1)
		if (all->calcpxls.sidedistx < all->calcpxls.sidedisty)
		{
			all->calcpxls.sidedistx += all->calcpxls.deltadistx;
			all->calcpxls.mapx += all->calcpxls.stepx;
			all->calcpxls.side = 0;
		}
		else
		{
			all->calcpxls.sidedisty += all->calcpxls.deltadisty;
			all->calcpxls.mapy += all->calcpxls.stepy;
			all->calcpxls.side = 1;
		}
}

void	drawwalls(t_all *all)
{
	if (all->calcpxls.side == 0 &&
		all->init.posx > all->calcpxls.raydirx + all->init.posx)
		my_mlx_pixel_put(all, all->init.x, all->init.y,
				texpixcolor(&all->img[0],
				all->tex.texx, spritetexy(all, &all->img[0])));
	else if (all->calcpxls.side == 0)
		my_mlx_pixel_put(all, all->init.x, all->init.y,
				texpixcolor(&all->img[1],
				all->tex.texx, spritetexy(all, &all->img[1])));
	if (all->calcpxls.side == 1 &&
		all->init.posy > all->calcpxls.raydiry + all->init.posy)
		my_mlx_pixel_put(all, all->init.x, all->init.y,
				texpixcolor(&all->img[2], all->tex.texx,
				spritetexy(all, &all->img[2])));
	else if (all->calcpxls.side == 1)
		my_mlx_pixel_put(all, all->init.x, all->init.y,
				texpixcolor(&all->img[3],
				all->tex.texx, spritetexy(all, &all->img[3])));
}

void	drawcub3d(t_all *all)
{
	all->init.y = -1;
	while (++all->init.y < all->parsvars.screenheight)
		if (all->init.y < all->calcpxls.drawstart)
			my_mlx_pixel_put(all, all->init.x, all->init.y,
			(0 << 24 | all->clr.f_r << 16 | all->clr.f_g << 8 | all->clr.f_b));
		else if (all->init.y <=
		all->calcpxls.drawend && all->init.y >= all->calcpxls.drawstart)
			drawwalls(all);
		else
			my_mlx_pixel_put(all, all->init.x, all->init.y,
			(0 << 24 | all->clr.c_r << 16 | all->clr.c_g << 8 | all->clr.c_b));
}

void	playerplane(t_all *all)
{
	all->calcpxls.camerax = 2 * all->init.x /
			(double)all->parsvars.screenwidth - 1;
	all->calcpxls.raydirx = all->init.dirx + all->init.planex *
			all->calcpxls.camerax;
	all->calcpxls.raydiry = all->init.diry + all->init.planey *
			all->calcpxls.camerax;
	all->calcpxls.mapx = (int)(all->init.posx);
	all->calcpxls.mapy = (int)(all->init.posy);
	all->calcpxls.deltadistx = fabs(1 / all->calcpxls.raydirx);
	all->calcpxls.deltadisty = fabs(1 / all->calcpxls.raydiry);
}

void	wallheight(t_all *all)
{
	if (all->calcpxls.side == 0)
		all->calcpxls.perpwalldist = (all->calcpxls.mapx - all->init.posx +
				((1 - all->calcpxls.stepx) / 2)) / all->calcpxls.raydirx;
	else
		all->calcpxls.perpwalldist = (all->calcpxls.mapy - all->init.posy +
				((1 - all->calcpxls.stepy) / 2)) / all->calcpxls.raydiry;
	all->calcpxls.lineheight =
			(int)(all->parsvars.screenheight / all->calcpxls.perpwalldist);
	all->calcpxls.drawstart =
			-all->calcpxls.lineheight / 2 + all->parsvars.screenheight / 2;
	if (all->calcpxls.drawstart < 0)
		all->calcpxls.drawstart = 0;
	all->calcpxls.drawend =
			all->calcpxls.lineheight / 2 + all->parsvars.screenheight / 2;
	if (all->calcpxls.drawend >= all->parsvars.screenheight)
		all->calcpxls.drawend = all->parsvars.screenheight - 1;
}
