/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joojeon <joojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:43:46 by jajo              #+#    #+#             */
/*   Updated: 2024/08/21 14:47:08 by jajo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FAIL 1
# define SUCCESS 0
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define PI 3.141592
# define RAY_RANGE (PI / 3.0)
# define RAY_COUNT 121
# define texWidth 64
# define texHeight 64
# define FALSE 0
# define TRUE 1

# include "./minilibx-linux/mlx.h"
//# include "./minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

typedef struct s_ray {
	double	ray_angle;
	double	wall_hitX;
	double	wall_hitY;
	double	distance;
	int		wasHit_vertical;
	int		isRay_facingDown;
	int		isRay_facingUp;
	int		isRay_facingRight;
	int		isRay_facingLeft;
}	t_ray;

typedef struct s_dpable_ray {
	double	ray_dir_x;
	double	ray_dir_y;
	double	x_intercept;
	double	y_intercept;
	double	x_step;
	double	y_step;
	int		found_wall_hit;
	int		side;
	double	wall_hitX;
	double	wall_hitY;
	double	distance;
	
	double	sdx;
	double	ddx;
	double	sdy;
	double	ddy;
	double	perpWallDist;
	int	lineHeight;
	int	verLineDrawStart;
	int	verLineDrawEnd;
}	t_dpable_ray;

typedef enum s_direction {
	WEST,
	SOUTH,
	EAST,
	NORTH
}	t_direction;

typedef struct s_img {
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_img;

typedef struct s_tmptex {
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_tmptex;

typedef struct s_texture {
	char	*text_path;
	int		*texture;
	void	*ptr;
	int		width;
	int		height;
}	t_texture;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

typedef struct s_map {
	t_texture	texture[4];
	t_color		floor_color;
	t_color		ceiling_color;
	t_field		*field;
	t_point		*start;
	t_point		*end;
	int			**array_map;
	int			max_width;
	int			map_height;
	int			zoom;
	int			tile_len;
}	t_map;

typedef struct s_user {
	double			x;
	double			y;
	double			dx;
	double			dy;
	double			v_dx;
	double			v_dy;
	int			degree; //north = 90, east = 0, south = 270, west = 180;
	t_direction	direct;
}	t_user;

typedef struct s_cub3d {
	t_map	map;
	t_img	*img;
	t_user	user;
	t_ray	ray;
	/* mlx variable */
	void	*mlx;
	void	*win;
}	t_cub3d;

/* ray_2d.c */
void	draw_ray_2d(t_cub3d *cub3d);


void	init_window(t_cub3d *cub3d);
/* tmp.c */
void	print_field(t_field *field);
void	print_array_map(t_cub3d *cub3d);

/* 3d.c */
void	ver_line(t_cub3d *cub3d, int x, double height, int color, int wall_dir);
void	ver_line_2d(t_cub3d *cub3d, int x, int color, int wall_dir);

/* ray.c */
void	draw_ray(t_cub3d *cub3d);
double	get_height_ratio(t_cub3d *cub3d, int i, int x);
double	get_distance(t_cub3d *cub3d, int i);

/* ray_utils.c */
double	deg2rad(double degree);
double	rad2deg(double radians);
void	coordi_ray_point(t_cub3d *cub3d, double *x, double *y);
int		is_correct_ray_coordi(t_cub3d *cub3d, int i);

/* draw_map.c */
void	make_it_3d(t_cub3d *cub3d);

/* draw_minimap.c */
int		draw_minimap(t_cub3d *cub3d);
void	fill_square(t_cub3d *cub3d, int x, int y, int color);
void	draw_player(t_cub3d *cub3d);

/* draw_utils.c */
void	my_mlx_pixel_put(t_cub3d *cub3d, int x, int y, int color);
void	coordinate_point(t_cub3d *cub3d, t_point *start, t_point *end);
void	coordinate_spot(t_cub3d *cub3d, double *x, double *y);
void	my_mlx_pixel_put_double(t_cub3d *cub3d, double x, double y, int color);

/* key_hook.c */
int		handle_key(int key, t_cub3d *cub3d);
int		exit_program(void *t_cub3d);

/* key_move.c */
void	move(int key, t_cub3d *cub3d);

/* free.c */
void	free_map(t_cub3d *cub3d);
void	free_texture(t_cub3d *cub3d);
void	free_second_char_arr(char **str);

/* map.c */
void	parse_map(t_cub3d *cub3d, char *filename);

/* map_user.c */
void	get_user_direction(t_cub3d *cub3d, char c);

/* map_utils.c */
void	save_max_line_num(t_cub3d *cub3d);
void	make_field_rectangle(t_cub3d *cub3d);
void	make_field_array(t_cub3d *cub3d);
void	get_tile_len(t_cub3d *cub3d);

/* map_color.c */
int		parse_map_color(t_cub3d *cub3d, char *str);

/* map_texture.c */
int		parse_map_texture(t_cub3d *cub3d, char *str);

/* error.c */
void	error(int error_num);

/* validation.c */
void	is_valid_input(int argc, char *argv[]);

/* validation_field.c */
int		is_valid_field(t_cub3d *cub3d);
int		is_valid_player(t_cub3d *cub3d);

/* validation_field_utils.c */
int		check_prev_field(t_field *prev_field, int idx);
int		check_next_field(t_field *next_field, int idx);
int		check_current_field(t_field *field, int idx);

#endif
