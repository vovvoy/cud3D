/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:47:48 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/31 00:01:58 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			keycode_4(int keycode, t_all *all)
{
	if (keycode == 0)
	{
		if (!(all->parsvars.worldmap[(int)(all->init.posx - all->init.diry *
				all->move.movespeed)][(int)(all->init.posy)]))
			all->init.posx -= all->init.diry * all->move.movespeed;
		if (!(all->parsvars.worldmap[(int)(all->init.posx)]
				[(int)(all->init.posy + all->init.dirx * all->move.movespeed)]))
			all->init.posy += all->init.dirx * all->move.movespeed;
	}
	if (keycode == 2)
	{
		if (!(all->parsvars.worldmap[(int)(all->init.posx)]
				[(int)(all->init.posy - all->init.dirx * all->move.movespeed)]))
			all->init.posy -= all->init.dirx * all->move.movespeed;
		if (!(all->parsvars.worldmap[(int)(all->init.posx + all->init.diry *
				all->move.movespeed)][(int)(all->init.posy)]))
			all->init.posx += all->init.diry * all->move.movespeed;
	}
}

void			keycode_3(int keycode, t_all *all)
{
	if (keycode == 13)
	{
		if (!(all->parsvars.worldmap[(int)(all->init.posx +
				all->init.dirx * all->move.movespeed)][(int)(all->init.posy)]))
			all->init.posx += all->init.dirx * all->move.movespeed;
		if (!(all->parsvars.worldmap[(int)(all->init.posx)]
				[(int)(all->init.posy + all->init.diry * all->move.movespeed)]))
			all->init.posy += all->init.diry * all->move.movespeed;
	}
	if (keycode == 123)
	{
		all->move.olddirx = all->init.dirx;
		all->init.dirx = all->init.dirx *
			cos(all->move.rotspeed) - all->init.diry * sin(all->move.rotspeed);
		all->init.diry = all->move.olddirx *
			sin(all->move.rotspeed) + all->init.diry * cos(all->move.rotspeed);
		all->move.oldplanex = all->init.planex;
		all->init.planex = all->init.planex * cos(all->move.rotspeed) -
			all->init.planey * sin(all->move.rotspeed);
		all->init.planey = all->move.oldplanex * sin(all->move.rotspeed) +
			all->init.planey * cos(all->move.rotspeed);
	}
}

void			keycode_2(int keycode, t_all *all)
{
	if (keycode == 1)
	{
		if (!(all->parsvars.worldmap[(int)(all->init.posx -
			all->init.dirx * all->move.movespeed)][(int)(all->init.posy)]))
			all->init.posx -= all->init.dirx * all->move.movespeed;
		if (!(all->parsvars.worldmap[(int)(all->init.posx)]
				[(int)(all->init.posy - all->init.diry * all->move.movespeed)]))
			all->init.posy -= all->init.diry * all->move.movespeed;
	}
	if (keycode == 124)
	{
		all->move.olddirx = all->init.dirx;
		all->init.dirx = all->init.dirx * cos(-all->move.rotspeed) -
			all->init.diry * sin(-all->move.rotspeed);
		all->init.diry = all->move.olddirx * sin(-all->move.rotspeed) +
			all->init.diry * cos(-all->move.rotspeed);
		all->move.oldplanex = all->init.planex;
		all->init.planex = all->init.planex * cos(-all->move.rotspeed) -
			all->init.planey * sin(-all->move.rotspeed);
		all->init.planey = all->move.oldplanex * sin(-all->move.rotspeed) +
			all->init.planey * cos(-all->move.rotspeed);
	}
}

void			keycode_1(int keycode)
{
	if (keycode == 53)
	{
		write(1, "See you !!!\n", 12);
		exit(0);
	}
}

int				move(int keycode, t_all *all)
{
	keycode_1(keycode);
	keycode_2(keycode, all);
	keycode_3(keycode, all);
	keycode_4(keycode, all);
	calcpxls(all);
	return (1);
}
