/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:10:13 by asablayr          #+#    #+#             */
/*   Updated: 2020/03/11 10:40:16 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef CUBE_H
# define CUBE_H

# ifndef CHARSET
#  define CHARSET	"012NESW"
# endif

# ifndef TXT_PATH
#  define TXT_PATH	"./textures/"
# endif

# ifndef SPEED
#  define SPEED	0.1
# endif

# ifndef LOOK_SPEED
#  define LOOK_SPEED	(M_PI/40)
# endif

# ifndef BLOCK_SIZE
#  define BLOCK_SIZE 1
# endif

# ifndef BLOCK_MAP
#  define BLOCK_MAP 10
# endif

typedef	struct	s_player
{
	float	x;
	float	y;
	int		x_pos;
	int		y_pos;
	int		life;
	int		stamina;
	double	dir;
	double 	fov;
}				t_player;

typedef	struct	s_image
{
	int		x;
	float	x_txt;
	int		y;
	float	y_txt;
	int		size_l;
	int		bpp;
	int		endian;
	void		*ptr;
	int		*d_ptr;
	int		index;
}				t_img;

typedef struct	s_hud
{
	float	s;
	int	offset;
	int	offset_y;
	t_img	t;
}		t_hud;

typedef	struct	s_ray
{
	float	h;
	float	h_x;
	float	h_y;
	float	v;
	float	v_x;
	float	v_y;
	double	d;
	int		side;
}				t_ray;

typedef struct	s_bmp
{
	int		file_size;
	int		pixels_adr;
	int		header_size;
	short	clrs_planes;
	short	bpp;
	int		raw_size;
	int		res;
}				t_bmp;

typedef struct	s_sprite
{
	float	x;
	float	y;
	float	dist;
	double	dir;
}				t_sprite;

typedef	struct	s_settings
{
	int		res_x;
	int		res_y;
	char	*t_n;
	char	*t_e;
	char	*t_s;
	char	*t_w;
	char	*t_sp;
	int		*rgb_f;
	int		*rgb_c;
	int		c_f;
	int		c_c;
	char	**map;
	int		map_x;
	int		map_y;

}				t_settings;

typedef struct	s_input
{
	char	w;
	char	d;
	char	s;
	char	a;
	char	right;
	char	left;
	char	aim;
	char	run;
	char	pause;
	char	shoot;
}				t_input;

typedef struct	s_game
{
	t_settings	set;
	t_player	p;
	t_input		press;
	t_img		img;
	t_img		txt[10];
	t_hud		hud[5];
	t_ray		r;
	float		*z_buff;
	int			sp_num;
	int			s_dist;
	t_sprite	*sp;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_game;

void			init_game(t_game *game);
int				convert_color(int *rgb);
void			get_color(int *set, char *str);
char			*get_text(char *str);
void			get_res(int *res_x, int *res_y, char *str);
void			init_set(t_settings *set);
void			get_settings(t_settings *set, int fd);
int				in_set(char c, char *charset);
int				parse(t_settings *set);
int				check_file(char *str);
int				check_utils(void);
int				check_map(char **map, int *h, int *w);
void			init_game(t_game *g);
void			init_player(t_game *g);
void			load_txt(t_img *t, t_game g, char *path);
void			set_hooks(t_game *game);
int				game_loop(t_game *game);
void			move_front(t_player *p, t_game *g);
void			move_right(t_player *p, t_game *g);
void			move_back(t_player *p, t_game *g);
void			move_left(t_player *p, t_game *g);
void			look_right(t_player *p, char c);
void			look_left(t_player *p, char c);
void			raycast(t_game g);
void			reset_dir(double *d);
float			get_wall_h(t_game *g, t_ray *r);
float			get_wall_v(t_game *g, t_ray *r);
float			get_dist(t_game *g, double d, t_ray *r);
int				check_w(t_game *g, float x, float y);
t_img			select_text(t_game g);
unsigned int	get_txt_color(t_img t, int x, int y);
void			init_sprite(t_game *g, t_settings s);
void			init_hud(t_game *g);
void			draw_column(t_game g, double d, int x);
void			draw_window(t_game *g);
void			draw_ray(t_img i, t_player p, double dir, int d);
void			draw_square(t_img i, int c, int x, int y);
void			draw_line(t_img *i, int x, int y, int dist);
void			draw_map(t_game *g);
void			draw_weapon(t_hud hud, t_img *img);
void			draw_icon(t_hud t, t_img i);
void			draw_cursor(t_img *img);
void			draw_hud(t_game *g);
void			draw_aim(t_hud h, t_img *img);
void			draw_death(t_hud h, t_img *img);
int				skip_pix(t_img t, int j, int i);
double			sprite_dir(t_player p, t_sprite sp);
float			sprite_dist(t_player *p, t_sprite *sp);
int				sp_in_fov(t_player p, t_sprite sp);
int				sprite_bite(t_game *g);
void			shoot(t_player p, t_game *g);
t_sprite		*sort_sprite(t_sprite *sp, int count);
void			draw_sprite(t_game *g);
void			screenshot(t_img i);
int				clean_exit(int error, t_game *game);

#endif
