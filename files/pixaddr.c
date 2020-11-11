/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixaddr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 21:58:51 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/30 22:26:58 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	texpixcolor(t_img *img, int x, int y)
{
	char			*addr;
	unsigned int	color;

	addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	color = *(unsigned int*)addr;
	return (color);
}

void			my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
	char		*dst;
	const int	mask = 0xFF000000;

	dst = all->mlx.addr +
		(y * all->mlx.line_length + x * (all->mlx.bits_per_pixel / 8));
	if (!(color & mask))
		*(unsigned int*)dst = color;
}
