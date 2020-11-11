/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerrica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:38:32 by ljerrica          #+#    #+#             */
/*   Updated: 2020/10/30 23:40:33 by ljerrica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlxOpenGL/mlx.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct	s_sprts_xy
{
	double		x;
	double		y;
}				t_sprts_xy;

typedef struct	s_color
{
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
}				t_clr;

typedef struct	s_sprites
{
	int			sprnum;
	int			*spriteorder;
	double		*spritedistance;
	t_sprts_xy	*sprite;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawstartx;
	int			drawendy;
	int			drawendx;
	double		*zbuffer;
	int			texx;
	int			texy;
}				t_sprites;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx;

typedef struct	s_tex
{
	double		wallx;
	int			texx;
	double		step;
	double		texpos;
	int			texy;
}				t_tex;

typedef struct	s_calcpxls
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		mapx;
	double		mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		stepx;
	double		stepy;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		*zbuffer;
}				t_calcpxls;

typedef struct	s_parsvars
{
	int			screenwidth;
	int			screenheight;
	int			**worldmap;
}				t_parsvars;

typedef struct	s_init
{
	int			x;
	int			y;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
}				t_init;

typedef struct	s_move
{
	double		movespeed;
	double		rotspeed;
	double		olddirx;
	double		oldplanex;
}				t_move;

typedef struct	s_all
{
	t_mlx		mlx;
	t_calcpxls	calcpxls;
	t_parsvars	parsvars;
	t_init		init;
	t_move		move;
	t_img		img[5];
	t_tex		tex;
	t_sprites	sprts;
	t_clr		clr;
	char		*save;
}				t_all;

typedef struct	s_play_ground
{
	int			pos_x;
	int			pos_y;
	int			qntty;
	char		dir;
	int			width;
	int			abs_width;
	int			height;
}				t_plr;

typedef struct	s_init_map
{
	int			win_w;
	int			win_h;
	char		*so;
	char		*no;
	char		*we;
	char		*ea;
	char		*s;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
}				t_imap;

typedef struct	s_map
{
	char		map_1;
}				t_map;

typedef struct	s_read
{
	int			fd;
	int			ret;
	char		*line;
}				t_read;
typedef struct	s_map_fist_part
{
	char		r;
	char		no;
	char		so;
	char		we;
	char		ea;
	char		s;
	char		f;
	char		c;
}				t_map1;
typedef struct	s_map_parser
{
	t_read		read;
	t_map1		map1;
	t_map		map;
	t_imap		imap;
	t_plr		plr;
	int			**map_arr;
	int			i;
	int			j;
	int			cnt;
}				t_pars;

unsigned int	texpixcolor(t_img *img, int x, int y);
void			my_mlx_pixel_put(t_all *all, int x, int y, int color);
void			spritesort(t_all *all);
void			wallhit(t_all *all);
int				spritetexy(t_all *all, t_img *img);
void			drawwalls(t_all *all);
void			drawcub3d(t_all *all);
void			spritedistcount(t_all *all);
void			playerplane(t_all *all);
void			sidedistcount(t_all *all);
void			textotexcont(t_all *all);
void			textotex(t_all *all);
void			walltexcount(t_all *all);
void			wallheight(t_all *all);
void			drawprep(t_all *all);
void			drawsprite(t_all *all);
void			sprite_xy(t_all *all);
void			spritescount(t_all *all);
void			calcpxls(t_all *all);
void			keycode_4(int keycode, t_all *all);
void			keycode_3(int keycode, t_all *all);
void			keycode_2(int keycode, t_all *all);
void			keycode_1(int keycode);
int				move(int keycode, t_all *all);
int				ft_close(void);
void			spritescount(t_all *all);

void			player_pos(t_pars *pars, t_all *all);
void			player_pos1(t_pars *pars, t_all *all);
void			pars_all(t_pars *pars, t_all *all);
void			pars_sprite(t_pars *pars, t_all *all);
void			init_sprite(t_all *all);
void			fill_sprite(t_pars *pars, t_all *all);
void			start_loop(t_all *all);
void			tex_init(t_pars *pars, t_all *all);
void			end_loop(t_all *all);

void			save(t_all all);
void			check_argument(char *save);

int				get_next_line(int fd, char **line);
int				strl(char *str);
char			*strj(char *s1, char s2);
void			map_pars(char *f_name, t_pars *pars);
void			map_1_1r(t_pars *pars);
void			map_path(t_pars *pars, char **path, char *id);
void			error(char *message);
void			map_1_1(t_pars *pars);
void			map_1(t_pars *pars);
char			*xpm_path(t_pars *pars);
int				val_int(char *str, t_pars *pars, int num);
int				words_count(t_pars *pars);
char			**split(char const *s, char c);
int				match(char *str, char ch);
int				color_code(t_pars *pars);
void			gnl_2(t_pars *pars, char *f_name);
void			fill_map(t_pars *pars);
void			pars_init_2(t_pars *pars);
void			pars_init(t_pars *pars);
void			init_map(t_pars *pars);
void			map_2(t_pars *pars);
void			map_ccode(t_pars *pars, int flr_ceil, char *id);
void			map_1_check(t_pars *pars);
void			map_ccode_1(t_pars *pars);
void			map_ccode_2(t_pars *pars);
void			filling_map(t_pars *pars);

#endif
