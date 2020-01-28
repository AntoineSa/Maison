/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asablayr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:10:13 by asablayr          #+#    #+#             */
/*   Updated: 2020/01/28 16:07:42 by asablayr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# ifndef SPEED
#  define SPEED	0.08
# endif

# ifndef BLOCK_SIZE
#  define BLOCK_SIZE 1
# endif

# ifndef BLOCK_MAP
#  define BLOCK_MAP 5
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
	int		*data_ptr;
}				t_img;

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
}				t_input;

typedef struct	s_game
{
	t_settings	set;
	t_player	p;
	t_input		press;
	t_img		img;
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
void		move_front(t_player *p, t_settings s);
void		move_right(t_player *p, t_settings s);
void		move_back(t_player *p, t_settings s);
void		move_left(t_player *p, t_settings s);
void		look_right(t_player *p);
void		look_left(t_player *p);
void		raycast(t_game g);
void		reset_dir(double *d);
float		get_dist(t_game gamei, double d);
float		*get_h_const(float dir);
float		*get_v_const(float dir);
int			check_w(double d, t_settings s, float x, float y);
void		draw_column(t_game g, double d, int x);
void		draw_window(t_img i);
void		draw_square(t_img i, int c, int x, int y);
void		draw_map(t_game g);
int			clean_exit(int error, t_game *game);

#endif
