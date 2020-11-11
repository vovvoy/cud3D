/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:46:31 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/31 14:46:38 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		spritetexy(t_all *all, t_img *img)
{
	all->tex.texy =
			(int)all->tex.texpos & (img->height - 1);
	all->tex.texpos += all->tex.step;
	return (all->tex.texy);
}

void	spritedistcount(t_all *all)
{
	all->init.x = -1;
	while (++all->init.x < all->sprts.sprnum)
	{
		all->sprts.spriteorder[all->init.x] = all->init.x;
		all->sprts.spritedistance[all->init.x] =
				((all->init.posx - all->sprts.sprite[all->init.x].x) *
				(all->init.posx - all->sprts.sprite[all->init.x].x) +
				(all->init.posy - all->sprts.sprite[all->init.x].y) *
				(all->init.posy - all->sprts.sprite[all->init.x].y));
	}
}

void	sidedistcount(t_all *all)
{
	if (all->calcpxls.raydirx < 0)
	{
		all->calcpxls.stepx = -1;
		all->calcpxls.sidedistx = (all->init.posx - all->calcpxls.mapx) *
				all->calcpxls.deltadistx;
	}
	else
	{
		all->calcpxls.stepx = 1;
		all->calcpxls.sidedistx = (all->calcpxls.mapx + 1.0 - all->init.posx) *
				all->calcpxls.deltadistx;
	}
	if (all->calcpxls.raydiry < 0)
	{
		all->calcpxls.stepy = -1;
		all->calcpxls.sidedisty = (all->init.posy - all->calcpxls.mapy) *
				all->calcpxls.deltadisty;
	}
	else
	{
		all->calcpxls.stepy = 1;
		all->calcpxls.sidedisty = (all->calcpxls.mapy + 1.0 - all->init.posy) *
				all->calcpxls.deltadisty;
	}
}

void	textotex(t_all *all)
{
	if (all->calcpxls.side == 0 &&
		all->init.posx > all->calcpxls.raydirx + all->init.posx)
	{
		all->tex.texx = (int)(all->tex.wallx * (double)(all->img[0].width));
		if (all->calcpxls.side == 0 && all->calcpxls.raydirx > 0)
			all->tex.texx = all->img[0].width - all->tex.texx - 1;
		if (all->calcpxls.side == 1 && all->calcpxls.raydiry < 0)
			all->tex.texx = all->img[0].width - all->tex.texx - 1;
		all->tex.step = 1.0 * all->img[0].height / all->calcpxls.lineheight;
	}
	else if (all->calcpxls.side == 0)
	{
		all->tex.texx = (int)(all->tex.wallx * (double)(all->img[1].width));
		if (all->calcpxls.side == 0 && all->calcpxls.raydirx > 0)
			all->tex.texx = all->img[1].width - all->tex.texx - 1;
		if (all->calcpxls.side == 1 && all->calcpxls.raydiry < 0)
			all->tex.texx = all->img[1].width - all->tex.texx - 1;
		all->tex.step = 1.0 * all->img[1].height / all->calcpxls.lineheight;
	}
	textotexcont(all);
}

void	drawprep(t_all *all)
{
	all->sprts.spritewidth =
			abs((int)(all->parsvars.screenheight / all->sprts.transformy));
	all->sprts.drawstartx =
			-all->sprts.spritewidth / 2 + all->sprts.spritescreenx;
	if (all->sprts.drawstartx < 0)
		all->sprts.drawstartx = 0;
	all->sprts.drawendx =
			all->sprts.spritewidth / 2 + all->sprts.spritescreenx;
	if (all->sprts.drawendx >= all->parsvars.screenwidth)
		all->sprts.drawendx = all->parsvars.screenwidth - 1;
}
