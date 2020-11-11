/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 02:50:28 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 15:09:45 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		error(char *message)
{
	write(1, "Error\n", 6);
	write(1, message, strl(message));
	exit(1);
}

void		check_argument(char *save)
{
	if (save[0] == '-' &&
		save[1] == '-' &&
		save[2] == 's' &&
		save[3] == 'a' &&
		save[4] == 'v' &&
		save[5] == 'e' &&
		save[6] == '\0')
		return ;
	else
		error("Wrong third argument!!!\n");
}

static void	map_file(char *str)
{
	int		cnt;

	cnt = strl(str) - 1;
	if (str[cnt] == 'b' &&
		str[cnt - 1] == 'u' &&
		str[cnt - 2] == 'c' &&
		str[cnt - 3] == '.')
		return ;
	error("Invalid map extention!!!\n");
}

int			main(int argc, char *argv[])
{
	t_pars	pars;
	t_all	all;

	if (argc == 1)
		error("No map!!!\n");
	if (argc > 3)
		error("Too many arguments!!!\n");
	if (argc == 3)
	{
		check_argument(argv[2]);
		all.save = argv[2];
	}
	map_file(argv[1]);
	pars_init(&pars);
	map_pars(argv[1], &pars);
	pars_all(&pars, &all);
	return (0);
}
