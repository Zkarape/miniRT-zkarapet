/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:12:09 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/07 13:24:04 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stddef.h>
# include <limits.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <pthread.h>
# include "../lib/minilibx_opengl/mlx.h"
# include "../lib/libft/libft.h"
# include "get_next_line.h"
# include "scene.h"
# include "vectorRay.h"

# define WIDTH 1600
# define HEIGHT 900
# define EPSILON 0.001
# define STRENGTH 0.5
# define SHININESS 32

typedef struct s_mlx
{
	void	*win;
	void	*mlx;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

typedef struct s_all
{
	t_mlx	*mlx_data;
	t_scene	*scene;
	int		x;
	int		y;
	int		check;
}	t_all;

typedef struct s_matrix
{
	t_vec	right;
	t_vec	up;
	t_vec	forward;
}	t_matrix;

typedef struct s_cross
{
	t_vec				n;
	t_vec				p;
	float				t;
	t_color				color;
}	t_cross;

typedef struct s_quadratic
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t1;
	float	t2;
}	t_quadratic;

t_color			col_mul(t_color a, t_color b);
void			exit_code(int code, char *msg, t_scene *scene, char **string);
void			parsing(int argc, char **argv, t_scene *scene);
void			print_vec(t_vec vec, char *msg);
//utils1.c
int				ft_double_len(char **str);
float			ft_atof(char *str);
bool			is_in_range_check(float number, float lower, float upper);
void			swap(float	*a, float *b);
float			find_min(float a, float b, float c);
//is_in_set.c
int				is_in_set(char c);
int				ft_isspace(char c);
//main.c
void			init_scene(t_scene *scene);
//split_m.c
char			**ft_split_m(char const *s);
//checkerUtils.c
int				only_digit_in_str(char *s);
int				color_range_check(t_color *tint);
int				vector_norm_check(t_vec *vector);
int				vector_range_check(t_vec *vector, \
				float lower_bound, float upper_bound);
//objectsInit.c
void			init_vector(t_vec vector, t_vec *objVect);
void			init_color(t_color tint, t_color *ambTint);
t_ambient		*init_ambient(float ratio, t_color tint, t_scene *scene);
t_cam			*init_cam(t_vec or, t_vec ori, float fov, t_scene *scene);
t_light			*initlight(t_vec orig, float ratio,
					t_color tint, t_scene *scene);
//checkers.c
void			check_vector(t_vec *v, float l, float u, t_scene *s);
void			check_color(t_color *tint, t_scene *scene);
void			checker_c(char **splitted_c, t_scene *scene);
void			checker_l(char **splitted_l, t_scene *scene);
void			checker_a(char **splitted_a, t_scene *scene);
void			checker_pl(char **splitted_pl, t_scene *scene);
void			checker_sp(char **splitted_sp, t_scene *scene);
void			checker_cy(char **splitted_cy, t_scene *scene);
//intersections
bool			intersect_plane(t_ray ray, t_plane plane, t_cross *cross);
bool			intersect_sphere(t_ray ray, t_sphere sphere, t_cross *cross);
bool			intersect_cylin(t_ray ray, t_cylinder cylin, t_cross *cross);
//ray.c
t_ray			ray_generate(float x, float y, t_cam camera);

// light.c
t_color			ambient_lighting(t_ambient *ambient);
t_color			diffuse_lighting(t_light *light, t_cross *cross);
t_color			specular_lightning(t_scene *scene, t_cross *cross);
bool			shadow(t_cross *cross, t_scene *scene);
t_color			final_lighting(t_scene *scene, t_cross *cross);

// light_utils.c
t_color			color_mul(t_color c, float f);
t_color			init_rgb(float r, float g, float b);
t_vec			reflect_vec(t_vec l, t_vec n);
void			point_calc(t_vec *p, t_ray r, float t);
t_color			final_color(t_cross *cross, t_color amb,
					t_color diff, t_color spec);

//normal.c
t_vec			sphere_normal(t_vec p, t_vec center);
t_vec			top_cap_center(t_cylinder cyl);
t_vec			bottom_cap_center(t_cylinder cyl);
t_vec			cylinder_normal(t_cylinder cylin, t_cross cross, float m);
void			render(t_all *all);

//colorOperations.c
unsigned int	make_int_from_rgb(t_color color);

//mlxFunctions.c
void			my_mlx_pixel_put(t_mlx *data,
					double x, double y, unsigned int color);
void			mlx_data_init(t_mlx *mlx_data);

//look_at.c
void			look_at(t_matrix *matrix, t_cam camera);

//ray_trace
bool			ray_trace(t_scene *scene, t_ray ray, t_cross **final_cross);

///cline
void			free_scene(t_scene *s);
int				is_rt_file(char *path);

#endif