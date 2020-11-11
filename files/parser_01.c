/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_01.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:59:52 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 18:59:55 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_1_1r(t_pars *pars)
{
	char	**vals;

	if (pars->map1.r)
		error("Wrong number of screen resolution!!!\n");
	if ((words_count(pars)) != 3)
		error("Wrong number of screen variables!!!\n");
	vals = split(pars->read.line, ' ');
	pars->imap.win_w = val_int(vals[1], pars, 1);
	pars->imap.win_h = val_int(vals[2], pars, 2);
	pars->map1.r = '1';
	free(vals[0]);
	free(vals[1]);
	free(vals[2]);
	free(vals);
}

void		map_path(t_pars *pars, char **path, char *id)
{
	if (*id == '1')
		error("Repeated texture path!!!\n");
	if (words_count(pars) != 2)
		error("Wrong number of texture path variables!!!\n");
	*path = xpm_path(pars);
	*id = '1';
}

void		map_ccode(t_pars *pars, int flr_ceil, char *id)
{
	pars->i = 1;
	if (*id == '1')
		error("Wrong number of color code variables!!!\n");
	if (flr_ceil == 1)
		map_ccode_2(pars);
	else if (flr_ceil == 2)
		map_ccode_1(pars);
	*id = '1';
}

void		map_1_1(t_pars *pars)
{
	if (pars->read.line[0] == 'R' && pars->read.line[1] == ' ')
		map_1_1r(pars);
	else if (pars->read.line[0] == 'S' && pars->read.line[1] == ' ')
		map_path(pars, &pars->imap.s, &pars->map1.s);
	else if (pars->read.line[0] == 'F' && pars->read.line[1] == ' ')
		map_ccode(pars, 1, &pars->map1.f);
	else if (pars->read.line[0] == 'C' && pars->read.line[1] == ' ')
		map_ccode(pars, 2, &pars->map1.c);
	else
		error("Invalid line on map!!!\n");
}

void		map_1_check(t_pars *pars)
{
	if (pars->map1.s == '1' &&
		pars->map1.r == '1' &&
		pars->map1.no == '1' &&
		pars->map1.so == '1' &&
		pars->map1.we == '1' &&
		pars->map1.ea == '1' &&
		pars->map1.c == '1' &&
		pars->map1.f == '1')
		pars->map.map_1 = '1';
}
