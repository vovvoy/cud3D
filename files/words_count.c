/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 18:58:29 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/02 18:58:33 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			words_count(t_pars *pars)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (pars->read.line[++i + 1])
		if (pars->read.line[i] != ' ' && pars->read.line[i + 1] == ' ')
			count++;
	if (pars->read.line[i] != ' ')
		count++;
	return (count);
}
