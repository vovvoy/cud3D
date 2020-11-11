/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:58:40 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 18:58:48 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int			val_int(char *str, t_pars *pars, int num)
{
	int		val;

	val = 0;
	pars->i = -1;
	while (str[++pars->i] > 47 && str[pars->i] < 58)
	{
		if (val < 10000)
			val = val * 10 + (str[pars->i] - 48);
	}
	if ((str[pars->i] > 57 || str[pars->i] < 48) && pars->i != strl(str))
		error("Wrong screen size!!!\n");
	if (val > 2560 && num == 1)
		val = 2560;
	else if (val > 1440 && num == 2)
		val = 1440;
	if (!val)
		error("Wrong screen size!!!\n");
	return (val);
}

char		*xpm_path(t_pars *pars)
{
	int		count;
	char	*str;

	count = 1;
	pars->i = strl(pars->read.line) - 1;
	while (!(pars->read.line[pars->i - 1] == ' '
			&& pars->read.line[pars->i] != ' '))
	{
		pars->i--;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (count + 1))))
		error("malloc!!!\n");
	str[count] = '\0';
	pars->i = strl(pars->read.line);
	while (count--)
		str[count] = pars->read.line[--pars->i];
	return (str);
}

int			color_code(t_pars *pars)
{
	int val;

	val = -1;
	while (pars->read.line[pars->i] != ',' && pars->read.line[pars->i])
	{
		if (!(match("0987654321, ", pars->read.line[pars->i])))
			error("Invalid letter(s)!!!\n");
		if (pars->read.line[pars->i] != ' ' && val == -1)
			val = 0;
		if (pars->read.line[pars->i] == ' ' && val == 0 &&
			pars->read.line[pars->i + 1] != ' '
			&& pars->read.line[pars->i + 1] != ',')
			error("Wrong color code!!!\n");
		if (pars->read.line[pars->i] != ' ')
			val = val * 10 + (pars->read.line[pars->i] - 48);
		if (val > 255)
			error("Color code more than 255!!!\n");
		pars->i++;
	}
	if (val == -1)
		error("No color code!!!/n");
	return (val);
}

int			match(char *str, char ch)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == ch)
			return (1);
	return (0);
}

void		fill_map(t_pars *pars)
{
	if (strl(pars->read.line) == 0)
		return ;
	pars->i++;
	pars->j = -1;
	while (pars->read.line[++pars->j])
	{
		if (match("NEWS", pars->read.line[pars->j]))
		{
			pars->map_arr[pars->i][pars->j] = 0;
			pars->plr.pos_x = pars->i;
			pars->plr.pos_y = pars->j;
			pars->plr.dir = pars->read.line[pars->j];
		}
		else if (pars->read.line[pars->j] != ' ')
			pars->map_arr[pars->i][pars->j] = pars->read.line[pars->j] - 48;
	}
}
