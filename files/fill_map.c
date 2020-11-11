/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 03:04:21 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/03 03:04:23 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void		map_row(t_pars *pars)
{
	int		i;

	i = pars->j;
	while (++i < pars->plr.height)
		if (pars->map_arr[pars->i][i] == 3 ||
			(i == pars->plr.abs_width - 1 && pars->map_arr[pars->i][i] != 1))
			error("Invalid map!!!\n");
		else if (pars->map_arr[pars->i][i] == 1)
			break ;
	i = pars->j;
	while (--i >= 0)
		if (pars->map_arr[pars->i][i] == 3 ||
			(i == 0 && pars->map_arr[pars->i][i] != 1))
			error("Invalid map!!!\n");
		else if (pars->map_arr[pars->i][i] == 1)
			break ;
}

static void		map_colomn(t_pars *pars)
{
	int		i;

	i = pars->i;
	while (--i >= 0)
		if (pars->map_arr[i][pars->j] == 3 ||
			(i == 0 && pars->map_arr[i][pars->j] != 1))
			error("Invalid map!!!\n");
		else if (pars->map_arr[i][pars->j] == 1)
			break ;
	i = pars->i;
	while (++i < pars->plr.height)
		if (pars->map_arr[i][pars->j] == 3 ||
			(i == pars->plr.height - 1 && pars->map_arr[i][pars->j] != 1))
			error("Invalid map!!!\n");
		else if (pars->map_arr[i][pars->j] == 1)
			break ;
}

void			filling_map(t_pars *pars)
{
	pars->i = -1;
	while (++pars->i < pars->plr.height)
	{
		pars->j = -1;
		while (++pars->j < pars->plr.abs_width)
		{
			if ((pars->map_arr[pars->i][pars->j] == 0 ||
				pars->map_arr[pars->i][pars->j] == 2) &&
				((pars->i != 0 && pars->i != pars->plr.height - 1) ||
				(pars->j != 0 && pars->j != pars->plr.abs_width - 1)))
			{
				map_colomn(pars);
				map_row(pars);
			}
			if ((pars->i == 0 || pars->i == pars->plr.height - 1 ||
			pars->j == 0 || pars->j == pars->plr.abs_width - 1) &&
			(pars->map_arr[pars->i][pars->j] == 2 ||
			pars->map_arr[pars->i][pars->j] == 0))
				error("Invalid map!!!\n");
		}
	}
}
