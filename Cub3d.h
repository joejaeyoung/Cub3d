/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joojeon <joojeon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:43:46 by jajo              #+#    #+#             */
/*   Updated: 2024/08/13 01:38:36 by joojeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FAIL 1
# define SUCCESS 0
# define WINDOW_WIDTH 1000
# define WINDOW_HEIGHT 600
# define PI 3.141592
# define RAY_RANGE (PI / 3.0)
# define RAY_COUNT 121

// # include "./minilibx-linux/mlx.h"
# include "./minilibx_opengl_20191021/mlx.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

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

typedef struct s_texture {
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}	t_texture;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	color;
}	t_color;

typedef struct s_map {
	t_texture	texture;
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
	int			degree; //north = 90, east = 0, south = 270, west = 180;
	t_direction	direct;
}	t_user;

typedef struct s_cub3d {
	t_map	map;
	t_img	*img;
	t_user	user;
	/* mlx variable */
	void	*mlx;
	void	*win;
}	t_cub3d;

/* tmp.c */
void	print_field(t_field *field);
void	print_array_map(t_cub3d *cub3d);

/* ray.c */
void	draw_ray(t_cub3d *cub3d);
int		is_wall(t_cub3d *cub3d, double x, double y);

/* ray_utils.c */
int		get_angle(t_direction d);
int		deg2rad(int degrees);
int		rad2deg(int radians);
void	coordi_ray_point(t_cub3d *cub3d, double *x, double *y);

/* ray_quad.c */
void	one_quadrants(t_cub3d *cub3d, int angle);
void	two_quadrants(t_cub3d *cub3d, int angle);
void	three_quadrants(t_cub3d *cub3d, int angle);
void	four_quadrants(t_cub3d *cub3d, int angle);
void	slope_verti_hori(t_cub3d *cub3d, int angle);

/* draw_map.c */
void	make_it_3d(t_cub3d *cub3d);

/* draw_minimap.c */
int	draw_minimap(t_cub3d *cub3d);

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

/* map_utils.c */
void	save_max_line_num(t_cub3d *cub3d);
void	make_field_rectangle(t_cub3d *cub3d);
void	make_field_array(t_cub3d *cub3d);

/* map_color.c */
int		parse_map_color(t_cub3d *cub3d, char *str);

/* map_texture.c */
int		parse_map_texture(t_cub3d *cub3d, char *str);

/* error.c */
void	error(int error_num);

/* validation.c */
void	is_valid_input(int argc, char *argv[]);
int		is_valid_player(t_cub3d *cub3d);

/* validation_field.c */
int		is_valid_field(t_cub3d *cub3d);

/* validation_field_utils.c */
int		check_prev_field(t_field *prev_field, int idx);
int		check_next_field(t_field *next_field, int idx);
int		check_current_field(t_field *field, int idx);

#endif
