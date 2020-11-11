/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:46:59 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 23:47:20 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		player_pos1(t_pars *pars, t_all *all)
{
	double		rot;

	if (pars->plr.dir == 'S')
		rot = M_PI;
	if (pars->plr.dir == 'W')
		rot = M_PI / 2;
	if (pars->plr.dir == 'E')
		rot = M_PI * 3 / 2;
	all->move.olddirx = all->init.dirx;
	all->init.dirx = all->init.dirx * cos(rot) -
		all->init.diry * sin(rot);
	all->init.diry = all->move.olddirx * sin(rot) +
		all->init.diry * cos(rot);
	all->move.oldplanex = all->init.planex;
	all->init.planex = all->init.planex * cos(rot) -
		all->init.planey * sin(rot);
	all->init.planey = all->move.oldplanex * sin(rot) +
		all->init.planey * cos(rot);
}

void		player_pos(t_pars *pars, t_all *all)
{
	all->init.dirx = -1;
	all->init.diry = 0;
	all->init.planex = 0;
	all->init.planey = 0.66;
	if (pars->plr.dir == 'N')
		return ;
	player_pos1(pars, all);
}

void		pars_sprite(t_pars *pars, t_all *all)
{
	all->parsvars.worldmap = pars->map_arr;
	all->move.movespeed = 0.35;
	all->move.rotspeed = 0.09;
	all->sprts.sprnum = 0;
	all->parsvars.screenheight = pars->imap.win_h;
	all->parsvars.screenwidth = pars->imap.win_w;
	pars->i = -1;
	while (++pars->i < pars->plr.height)
	{
		pars->j = -1;
		while (++pars->j < pars->plr.abs_width)
			if (all->parsvars.worldmap[pars->i][pars->j] == 2)
				all->sprts.sprnum++;
	}
}

void		fill_sprite(t_pars *pars, t_all *all)
{
	pars->i = -1;
	all->init.x = 0;
	while (++pars->i < pars->plr.height)
	{
		pars->j = -1;
		while (++pars->j < pars->plr.abs_width)
		{
			if (all->parsvars.worldmap[pars->i][pars->j] == 2)
			{
				all->sprts.sprite[all->init.x].x = pars->i;
				all->sprts.sprite[all->init.x].y = pars->j;
				all->init.x++;
			}
		}
	}
}

void		init_sprite(t_all *all)
{
	all->sprts.spritedistance = (double *)
	malloc(sizeof(double) * all->sprts.sprnum);
	all->sprts.spriteorder = (int *)
	malloc(sizeof(int) * all->sprts.sprnum);
	all->sprts.sprite = (t_sprts_xy *)
	malloc(sizeof(t_sprts_xy) * all->sprts.sprnum);
	all->sprts.zbuffer = (double *)
	malloc(sizeof(double) * all->parsvars.screenwidth);
}
