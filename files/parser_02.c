/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_02.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:59:31 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 18:59:33 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_2(t_pars *pars)
{
	if (strl(pars->read.line) == 0 && !pars->plr.height)
		return ;
	else if (strl(pars->read.line) == 0)
		error("Map with newline!!!\n");
	pars->i = -1;
	pars->plr.width = 0;
	while (pars->read.line[++pars->i])
	{
		if (!(match("NEWS 021", pars->read.line[pars->i])))
			error("Wrong letters on Map!!!\n");
		if (match("NEWS", pars->read.line[pars->i]))
		{
			pars->plr.qntty += 1;
			pars->plr.dir = pars->read.line[pars->i];
		}
	}
	if (pars->i > pars->plr.abs_width)
		pars->plr.abs_width = pars->i;
	pars->plr.width = pars->i;
	pars->plr.height++;
}

void		init_map(t_pars *pars)
{
	pars->i = -1;
	while (++pars->i < pars->plr.height)
	{
		pars->j = -1;
		while (++pars->j < pars->plr.abs_width)
			pars->map_arr[pars->i][pars->j] = 3;
	}
}

void		gnl_2(t_pars *pars, char *f_name)
{
	pars->read.ret = 1;
	if (pars->plr.qntty != 1)
		error("Wrong number of player!!!\n");
	if (!(pars->map_arr = (int **)malloc(sizeof(int*) * pars->plr.height)))
		error("malloc\n");
	pars->i = -1;
	while (++pars->i < pars->plr.height)
		if (!(pars->map_arr[pars->i] =
			(int *)malloc(sizeof(int) * pars->plr.abs_width)))
			error("malloc\n");
	init_map(pars);
	if ((pars->read.fd = open(f_name, O_RDONLY)) < 0)
		error("Can't open file!!!\n");
	pars->i = -1;
	while (pars->read.ret)
	{
		if ((pars->read.ret =
			get_next_line(pars->read.fd, &pars->read.line)) < 0)
			error("Can't read file!!!\n");
		if (pars->cnt <= 0)
			fill_map(pars);
		pars->cnt--;
		free(pars->read.line);
	}
}

void		pars_init_2(t_pars *pars)
{
	pars->imap.s = NULL;
	pars->imap.f_r = -1;
	pars->imap.f_g = -1;
	pars->imap.f_b = -1;
	pars->imap.c_r = -1;
	pars->imap.c_g = -1;
	pars->imap.c_b = -1;
	pars->map.map_1 = '0';
	pars->read.fd = -1;
	pars->read.ret = 1;
	pars->read.line = NULL;
	pars->map1.r = '\0';
	pars->i = -1;
	pars->j = -1;
	pars->cnt = 0;
}

void		pars_init(t_pars *pars)
{
	pars->plr.pos_x = -1;
	pars->plr.pos_y = -1;
	pars->plr.qntty = 0;
	pars->plr.dir = 'M';
	pars->plr.width = -1;
	pars->plr.abs_width = 0;
	pars->plr.height = 0;
	pars->imap.win_w = -1;
	pars->imap.win_h = -1;
	pars->imap.so = NULL;
	pars->imap.no = NULL;
	pars->imap.we = NULL;
	pars->imap.ea = NULL;
	pars_init_2(pars);
}
