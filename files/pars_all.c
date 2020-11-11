/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:41:16 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 23:41:18 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		end_loop(t_all *all)
{
	calcpxls(all);
	if (all->save)
		save(*all);
	else
	{
		mlx_hook(all->mlx.win, 2, 0, move, all);
		mlx_hook(all->mlx.win, 17, 17, ft_close, all);
		mlx_loop(all->mlx.mlx);
	}
}

void		tex_init(t_pars *pars, t_all *all)
{
	if (!(all->img[0].img = mlx_xpm_file_to_image(all->mlx.mlx,
			pars->imap.no, &all->img[0].width, &all->img[0].height)))
		error("Tex file invalid!!!\n");
	all->img[0].addr = mlx_get_data_addr(all->img[0].img,
	&all->img[0].bits_per_pixel, &all->img[0].line_length, &all->img[0].endian);
	if (!(all->img[1].img = mlx_xpm_file_to_image(all->mlx.mlx,
			pars->imap.so, &all->img[1].width, &all->img[1].height)))
		error("Tex file invalid!!!\n");
	all->img[1].addr = mlx_get_data_addr(all->img[1].img,
	&all->img[1].bits_per_pixel, &all->img[1].line_length, &all->img[1].endian);
	if (!(all->img[2].img = mlx_xpm_file_to_image(all->mlx.mlx,
			pars->imap.we, &all->img[2].width, &all->img[2].height)))
		error("Tex file invalid!!!\n");
	all->img[2].addr = mlx_get_data_addr(all->img[2].img,
	&all->img[2].bits_per_pixel, &all->img[2].line_length, &all->img[2].endian);
	if (!(all->img[3].img = mlx_xpm_file_to_image(all->mlx.mlx,
			pars->imap.ea, &all->img[3].width, &all->img[3].height)))
		error("Tex file invalid!!!\n");
	all->img[3].addr = mlx_get_data_addr(all->img[3].img,
	&all->img[3].bits_per_pixel, &all->img[3].line_length, &all->img[3].endian);
	if (!(all->img[4].img = mlx_xpm_file_to_image(all->mlx.mlx,
	pars->imap.s, &all->img[4].width, &all->img[4].height)))
		error("Tex file invalid!!!\n");
	all->img[4].addr = mlx_get_data_addr(all->img[4].img,
	&all->img[4].bits_per_pixel, &all->img[4].line_length, &all->img[4].endian);
}

void		floor_ceil(t_pars *pars, t_all *all)
{
	all->clr.f_r = pars->imap.f_r;
	all->clr.f_g = pars->imap.f_g;
	all->clr.f_b = pars->imap.f_b;
	all->clr.c_r = pars->imap.c_r;
	all->clr.c_g = pars->imap.c_g;
	all->clr.c_b = pars->imap.c_b;
}

void		start_loop(t_all *all)
{
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx,
		all->parsvars.screenwidth, all->parsvars.screenheight, "cub3D");
	all->mlx.img = mlx_new_image(all->mlx.mlx,
		all->parsvars.screenwidth, all->parsvars.screenheight);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img,
		&all->mlx.bits_per_pixel, &all->mlx.line_length, &all->mlx.endian);
}

void		pars_all(t_pars *pars, t_all *all)
{
	all->init.posx = pars->plr.pos_x + 0.5;
	all->init.posy = pars->plr.pos_y + 0.5;
	floor_ceil(pars, all);
	player_pos(pars, all);
	pars_sprite(pars, all);
	init_sprite(all);
	fill_sprite(pars, all);
	start_loop(all);
	tex_init(pars, all);
	end_loop(all);
}
