/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beginning.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 15:20:34 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/31 15:20:40 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	spritescount(t_all *all)
{
	int i;

	i = -1;
	while (++i < all->sprts.sprnum)
	{
		all->sprts.spritex =
				all->sprts.sprite[all->sprts.spriteorder[i]].x -
				all->init.posx + 0.5;
		all->sprts.spritey =
				all->sprts.sprite[all->sprts.spriteorder[i]].y -
				all->init.posy + 0.5;
		all->sprts.invdet =
				1.0 / (all->init.planex * all->init.diry -
				all->init.dirx * all->init.planey);
		all->sprts.transformx = all->sprts.invdet *
				(all->init.diry * all->sprts.spritex -
				all->init.dirx * all->sprts.spritey);
		all->sprts.transformy = all->sprts.invdet * (-all->init.planey *
				all->sprts.spritex + all->init.planex * all->sprts.spritey);
		all->sprts.spritescreenx = (int)((all->parsvars.screenwidth / 2) *
				(1 + all->sprts.transformx / all->sprts.transformy));
		sprite_xy(all);
	}
}

void	calcpxls(t_all *all)
{
	all->init.x = -1;
	while (++all->init.x < all->parsvars.screenwidth)
	{
		playerplane(all);
		sidedistcount(all);
		wallhit(all);
		wallheight(all);
		walltexcount(all);
		drawcub3d(all);
		all->sprts.
		zbuffer[all->init.x] = all->calcpxls.perpwalldist;
	}
	spritedistcount(all);
	spritesort(all);
	spritescount(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
}

int		ft_close(void)
{
	write(1, "See you !!!\n", 12);
	exit(0);
	return (0);
}
