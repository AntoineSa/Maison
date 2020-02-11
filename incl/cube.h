/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:10:13 by asablayr          #+#    #+#             */
/*   Updated: 2020/02/09 15:36:20 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef SPEED
#  define SPEED	0.05
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
	double	dir;
	double 	fov;
}				t_player;

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

typedef	struct	s_image
{
	int		x;
	int		y;
	int		size_l;
	int		bpp;
	int		endian;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*d_ptr;
}				t_img;

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
	char	*text;
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
	int	w;
	int	d;
	int	s;
	int	a;
	int	right;
	int	left;
	int	aim;
	int	run;
	int	pause;
}				t_input;

typedef struct	s_game
{
	t_settings	set;
	t_player	p;
	t_input		press;
	t_img		img;
	t_ray		r;
}				t_game;

void		init_game(t_game *game);
int			convert_color(int *rgb);
void		get_color(int *set, char *str);
char		*get_text(char *str);
void		get_res(int *res_x, int *res_y, char *str);
void		init_set(t_settings *set);
void		get_settings(t_settings *set, int fd);
int			in_set(char c, char *charset);
int			parse(t_settings *set);
int			check_map(char **map, int *h, int *w);
void		init_player(t_player *p, t_settings set);
void		init_img(t_img *img, t_game *g);
void		set_hooks(void *mlx_ptr, void *win_ptr, t_game *game);
int			game_loop(t_game *game);
void		move_front(t_player *p, t_game g);
void		move_right(t_player *p, t_game g);
void		move_back(t_player *p, t_game g);
void		move_left(t_player *p, t_game g);
void		look_right(t_player *p);
void		look_left(t_player *p);
void		raycast(t_game g);
void		reset_dir(double *d);
float		get_wall_h(t_game g, t_ray *r);
float		get_wall_v(t_game g, t_ray *r);
float		get_dist(t_game g, double d, t_ray *r);
int			check_w(t_game g, float x, float y);
char		*select_color(t_game g);
void		draw_column(t_game g, double d, int x);
void		draw_window(t_img i);
void		draw_line(t_img i, t_player p, double dir, int d);
void		draw_square(t_img i, int c, int x, int y);
void		draw_player(t_img i, int c, int x, int y);
void		draw_map(t_game g);
void		screenshot(t_img i);
int			clean_exit(int error, t_game *game);

#endif
