/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:09:55 by ljerrica          #+#    #+#             */
/*   Updated: 2020/11/04 19:09:59 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_bmp_header(t_all all, int fd)
{
	int		t;
	short	d;

	write(fd, "BM", 2);
	t = 14 + 40 + (int)all.parsvars.screenheight *
			(int)all.parsvars.screenwidth * 4;
	write(fd, &t, sizeof(t));
	d = 0;
	write(fd, &d, sizeof(d));
	write(fd, &d, sizeof(d));
	t = 14 + 40;
	write(fd, &t, sizeof(t));
}

void		ft_image_header(t_all all, int fd)
{
	int		t;
	short	d;

	t = 40;
	write(fd, &t, sizeof(t));
	t = (int)all.parsvars.screenwidth;
	write(fd, &t, sizeof(t));
	t = (int)all.parsvars.screenheight;
	write(fd, &t, sizeof(t));
	d = 1;
	write(fd, &d, sizeof(d));
	d = 32;
	write(fd, &d, sizeof(d));
	t = 0;
	write(fd, &t, sizeof(t));
	t = (int)all.parsvars.screenwidth *
			(int)all.parsvars.screenheight * 4;
	write(fd, &t, sizeof(t));
	t = 2795;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
	t = 0;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
}

void		save(t_all all)
{
	int		fd;
	char	*img;
	int		i;

	i = all.parsvars.screenheight;
	fd = open("screen.bmp", O_RDWR | O_CREAT | O_TRUNC, 00666);
	if (fd < 0)
		error("Can't open screen.bmp!!!\n");
	ft_bmp_header(all, fd);
	ft_image_header(all, fd);
	img = all.mlx.addr;
	while (i-- > 1)
		img += (int)all.parsvars.screenwidth * 4;
	while (i < all.parsvars.screenwidth)
	{
		write(fd, img, (int)all.parsvars.screenwidth * 4);
		img -= (int)all.parsvars.screenwidth * 4;
		i++;
	}
	close(fd);
}
