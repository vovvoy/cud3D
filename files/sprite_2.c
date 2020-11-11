/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 02:13:17 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/31 02:13:22 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spritesort(t_all *all)
{
	int			tmp;
	double		dst;
	int			i;
	int			j;

	i = -1;
	while (++i < all->sprts.sprnum - 1)
	{
		j = -1;
		while (++j < all->sprts.sprnum - 1)
			if (all->sprts.spritedistance[j] < all->sprts.spritedistance[j + 1])
			{
				dst = all->sprts.spritedistance[j];
				all->sprts.spritedistance[j] = all->sprts.spritedistance[j + 1];
				all->sprts.spritedistance[j + 1] = dst;
				tmp = all->sprts.spriteorder[j];
				all->sprts.spriteorder[j] = all->sprts.spriteorder[j + 1];
				all->sprts.spriteorder[j + 1] = tmp;
			}
	}
}

void	textotexcont(t_all *all)
{
	if (all->calcpxls.side == 1 &&
		all->init.posy > all->calcpxls.raydiry + all->init.posy)
	{
		all->tex.texx = (int)(all->tex.wallx * (double)(all->img[2].width));
		if (all->calcpxls.side == 0 && all->calcpxls.raydirx > 0)
			all->tex.texx = all->img[2].width - all->tex.texx - 1;
		if (all->calcpxls.side == 1 && all->calcpxls.raydiry < 0)
			all->tex.texx = all->img[2].width - all->tex.texx - 1;
		all->tex.step = 1.0 * all->img[2].height / all->calcpxls.lineheight;
	}
	else if (all->calcpxls.side == 1)
	{
		all->tex.texx = (int)(all->tex.wallx * (double)(all->img[3].width));
		if (all->calcpxls.side == 0 && all->calcpxls.raydirx > 0)
			all->tex.texx = all->img[3].width - all->tex.texx - 1;
		if (all->calcpxls.side == 1 && all->calcpxls.raydiry < 0)
			all->tex.texx = all->img[3].width - all->tex.texx - 1;
		all->tex.step = 1.0 * all->img[3].height / all->calcpxls.lineheight;
	}
}

void	walltexcount(t_all *all)
{
	if (all->calcpxls.side == 0)
		all->tex.wallx =
			all->init.posy + all->calcpxls.perpwalldist *
			all->calcpxls.raydiry;
	else
		all->tex.wallx = all->init.posx + all->calcpxls.perpwalldist *
				all->calcpxls.raydirx;
	all->tex.wallx -= floor((all->tex.wallx));
	textotex(all);
	all->tex.texpos = (all->calcpxls.drawstart - all->parsvars.screenheight /
			2 + all->calcpxls.lineheight / 2) * all->tex.step;
}

void	drawsprite(t_all *all)
{
	int d;

	all->init.x = all->sprts.drawstartx - 1;
	while (++all->init.x < all->sprts.drawendx)
	{
		all->sprts.texx = (int)(256 * (all->init.x -
				(-all->sprts.spritewidth / 2 +
				all->sprts.spritescreenx)) * all->img[4].width /
				all->sprts.spritewidth) / 256;
		all->init.y = all->sprts.drawstarty - 1;
		if (all->sprts.transformy > 0 && all->init.x <
			all->parsvars.screenwidth &&
			all->init.x > 0 && all->sprts.transformy <
			all->sprts.zbuffer[all->init.x])
			while (++all->init.y < all->sprts.drawendy)
			{
				d = (all->init.y) * 256 - all->parsvars.screenheight *
						128 + all->sprts.spriteheight * 128;
				all->sprts.texy = ((d * all->img[4].height) /
						all->sprts.spriteheight) / 256;
				my_mlx_pixel_put(all, all->init.x, all->init.y,
						texpixcolor(&all->img[4],
						all->sprts.texx, all->sprts.texy));
			}
	}
}

void	sprite_xy(t_all *all)
{
	all->sprts.spriteheight =
			abs((int)(all->parsvars.screenheight / all->sprts.transformy));
	all->sprts.drawstarty =
			-all->sprts.spriteheight / 2 + all->parsvars.screenheight / 2;
	if (all->sprts.drawstarty < 0)
		all->sprts.drawstarty = 0;
	all->sprts.drawendy =
			all->sprts.spriteheight / 2 + all->parsvars.screenheight / 2;
	if (all->sprts.drawendy >= all->parsvars.screenheight)
		all->sprts.drawendy = all->parsvars.screenheight - 1;
	drawprep(all);
	drawsprite(all);
}
