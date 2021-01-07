/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-bagh <ael-bagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:17:29 by ael-bagh          #+#    #+#             */
/*   Updated: 2021/01/06 19:31:08 by ael-bagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <ctype.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# define BUFFER_SIZE 10000
# define FLT_MAX 3.402823e+38

int				g_tile_size;
int				g_width;
int				g_height;
int				g_s_count;
char			*g_file;
char			*g_no;
char			*g_so;
char			*g_we;
char			*g_ea;
char			*g_s;
char			*g_map;
char			**g_map_array;
char			**g_map_finished;
int				g_fr;
int				g_fg;
int				g_fb;
int				g_cr;
int				g_cg;
int				g_cb;
int				g_map_started;
int				g_mapw;
int				g_maph;
static int		g_peeinit;
int				g_is_down;
int				g_is_up;
int				g_is_right;
int				g_is_left;
int				g_save;
int				get_next_line(int fd, char **line);
void			texture_error(int error);
void			free_this_shit(char *str, char **s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strlen(char *s);
size_t			ft_strlcpy(char *dst, char *src, size_t size);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strdup(char *s1);
char			*has_nl(char *str);
int				pre_work(int fd, char **rest, char **line);
char			**ft_split(char *str, char c);
int				c_w(char *str, char c);
void			get_re(char *line);
void			get_no(char *line);
void			get_we(char *line);
void			get_ea(char *line);
void			get_so(char *line);
void			get_s(char *line);
void			get_f(char *line);
void			get_c(char *line);
void			routing(char *line);
void			ft_putchar(char c);
void			ft_putstr(char *str);
void			ft_print_words_tables(char **tab);
char			**freethenipples(char **s);
int				s_p(char *s, char c);
int				len_str(char *s, int i, char c);
int				ft_isdigit(int c);
int				array_is_rgb(char **colors);
int				str_is_digits(char *c);
void			global_init(void);
int				all_params(void);
void			readmap(char *line);
void			manage_map(void);
void			longuest_line(void);
void			array_height(void);
void			map_manager(void);
void			map_closed(char **map);
int				only_ones(char *s);
int				begins_by_one(char *s);
char			*ft_strjoi(char *s1, char *s2);
int				begins_by_nl(char **maptab);
void			mapcheck(char **maptab);
void			wrong_file(char *file, int type);
int				wrong_resolution(int width, int height);
void			get_resolution(int width, int height);
void			check_crgb(char **colors, int cc, int cw);
void			check_frgb(char **colors, int cc, int cw);
void			get_crgb(int r, int g, int b);
void			get_frgb(int r, int g, int b);
void			error_redirect(int error);
void			fill_map(char **map);
void			surrend_by_spaces(char **map);
void			init_sprite(void);
void			to_sort(void);
void			to_sprite(void);
void			draw_sprite(int id);

typedef struct	s_player {
	float		x;
	float		y;
	float		fov;
	int			turn;
	int			walk;
	float		angle;
	float		speed;
	float		rspeed;
}				t_player;

t_player g_p;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

t_vars			g_vars;

typedef struct	s_rays {
	float		angle;
	float		hitx;
	float		hity;
	float		dist;
	int			hit_v;
	int			is_up;
	int			is_down;
	int			is_left;
	int			is_right;
}				t_rays;

t_rays			g_rays[2561];

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			en;
}				t_data;

t_data			g_img;
t_data			g_si;
t_data			g_nt;
t_data			g_st;
t_data			g_et;
t_data			g_wt;

typedef struct	s_prite
{
	float	x;
	float	xof;
	float	y;
	float	yof;
	float	dist;
	float	size;
}				t_sprite;

t_sprite		*g_sp;

typedef struct	s_ray
{
	float	x_intercept;
	float	y_intercept;
	float	ystep;
	float	xstep;
	int		found_horzhit;
	int		found_verthit;
	float	horz_hitx;
	float	vert_hitx;
	float	vert_hity;
	float	horz_hity;
	float	nhx;
	float	nvx;
	float	nvy;
	float	nhy;
	float	xcheck;
	float	ycheck;
	float	hdist;
	float	vdist;
}				t_ray;

t_ray			g_r;

typedef struct	s_colorbuffer
{
	float	perp_dist;
	float	distproj;
	float	projwallh;
	int		strip_h;
	int		walltop;
	int		wallbot;
	int		xoff;
	int		yoff;
	int		dist;
}				t_color;

t_color			g_col;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			draw_cube(int x, int y);
void			norm_it(char **meh);
void			draw_map(void);
void			cast_ray(int strip_id, float angle);
void			cast_rays(void);
int				has_wall(float x, float y);
float			normalangle(float rayangle);
void			render(void);
int				key_press(int keycode);
int				key_release(int keycode);
int				move(void);
void			generatel9lawi(void);
void			floor_ceiling(void);
void			sedat_madame(char **map);
int				check_map(int to_check, char c);
int				has_sprite(float x, float y);
void			init_textures(void);
void			ray_norm(int i);
int				assign_textures(int i);
void			vert_ray(float angle);
void			horz_ray(float angle);
void			push_ray(int strip_id);
float			dist_pts(float x1, float y1, float x2, float y2);
int				ft_quit(void);

typedef	struct	s_bmp_header
{
	char		type[2];
	u_int32_t	filesize;
	u_int16_t	reserved1;
	u_int16_t	reserved2;
	u_int32_t	pxdataoff;
	u_int32_t	headersize;
	int32_t		width;
	int32_t		height;
	u_int16_t	planes;
	u_int16_t	bpp;
	u_int32_t	compression;
	u_int32_t	imagesize;
	int32_t		xpermeter;
	int32_t		ypermeter;
	u_int32_t	totalcolors;
	u_int32_t	importantcolors;
}				t_bmp_file;

t_bmp_file		g_bmp;

void			save_bmp(void);

#endif
