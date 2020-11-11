/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_03.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:59:19 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 18:59:23 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		map_1(t_pars *pars)
{
	if (strl(pars->read.line) == 0)
		return ;
	if (strl(pars->read.line) < 5 && *pars->read.line != '\0')
		error("Wrong rule of map!!!\n");
	if (pars->read.line[0] == 'N' && pars->read.line[1] == 'O' &&
		pars->read.line[2] == ' ')
		map_path(pars, &pars->imap.no, &pars->map1.no);
	else if (pars->read.line[0] == 'S' && pars->read.line[1] == 'O' &&
		pars->read.line[2] == ' ')
		map_path(pars, &pars->imap.so, &pars->map1.so);
	else if (pars->read.line[0] == 'W' && pars->read.line[1] == 'E' &&
		pars->read.line[2] == ' ')
		map_path(pars, &pars->imap.we, &pars->map1.we);
	else if (pars->read.line[0] == 'E' && pars->read.line[1] == 'A' &&
		pars->read.line[2] == ' ')
		map_path(pars, &pars->imap.ea, &pars->map1.ea);
	else
		map_1_1(pars);
	map_1_check(pars);
}

void		map_pars(char *f_name, t_pars *pars)
{
	if ((pars->read.fd = open(f_name, O_RDONLY)) < 0)
		error("Can't open file!!!\n");
	while (pars->read.ret)
	{
		if ((pars->read.ret =
			get_next_line(pars->read.fd, &pars->read.line)) < 0)
			error("Can't read file!!!\n");
		if (pars->map.map_1 != '1')
		{
			pars->cnt++;
			map_1(pars);
		}
		else if (pars->cnt)
			map_2(pars);
		free(pars->read.line);
	}
	if ((close(pars->read.fd)) < 0)
		error("Can't close file!!!\n");
	gnl_2(pars, f_name);
	filling_map(pars);
}

void		map_ccode_1(t_pars *pars)
{
	int		comma;

	comma = 0;
	while (pars->i < strl(pars->read.line))
	{
		if (!(match("0987654321, ", pars->read.line[pars->i])))
			error("Wrong code of color!!!\n");
		if (comma == 0)
			pars->imap.f_r = color_code(pars);
		else if (comma == 1)
			pars->imap.f_g = color_code(pars);
		else if (comma == 2)
			pars->imap.f_b = color_code(pars);
		if (comma > 2)
			error("Wrong number of comma!!!\n");
		comma++;
		pars->i++;
	}
	if (comma != 3 || (comma == 3 && pars->read.line[pars->i - 1] == ','))
		error("Wrong number of comma!!!\n");
}

void		map_ccode_2(t_pars *pars)
{
	int		comma;

	comma = 0;
	while (pars->i < strl(pars->read.line))
	{
		if (!(match("0987654321, ", pars->read.line[pars->i])))
			error("Wrong code of color!!!\n");
		if (comma == 0)
			pars->imap.c_r = color_code(pars);
		else if (comma == 1)
			pars->imap.c_g = color_code(pars);
		else if (comma == 2)
			pars->imap.c_b = color_code(pars);
		if (comma > 2)
			error("Wrong number of comma!!!\n");
		comma++;
		pars->i++;
	}
	if (comma != 3 || (comma == 3 && pars->read.line[pars->i - 1] == ','))
		error("Wrong number of comma!!!\n");
}
