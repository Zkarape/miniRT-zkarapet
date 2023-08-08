/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:07:45 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:07:47 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_vector(t_vec *vector, float lower, float upper, t_scene *scene)
{
	if (ft_double_len(scene->vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for vector\n",
			scene, scene->vec_splitted);
	if (!only_digit_in_str(scene->vec_splitted[0]))
		exit_code(1, "X is invalid\n", scene, scene->vec_splitted);
	if (!only_digit_in_str(scene->vec_splitted[1]))
		exit_code(1, "Y is invalid\n", scene, scene->vec_splitted);
	if (!only_digit_in_str(scene->vec_splitted[2]))
		exit_code(1, "Z is invalid\n", scene, scene->vec_splitted);
	vector->x = ft_atof(scene->vec_splitted[0]);
	vector->y = ft_atof(scene->vec_splitted[1]);
	vector->z = ft_atof(scene->vec_splitted[2]);
	if (lower != -8 && vector_range_check(vector, lower, upper) == 0)
		exit_code(1, "Vector coordinates are out of range\n",
			scene, scene->vec_splitted);
	else if (lower == -8 && vector_norm_check(vector) == 0)
		exit_code(1, "Vector is not unit\n", scene, scene->vec_splitted);
	if (scene->vec_splitted)
		double_free(scene->vec_splitted);
}

void	check_color(t_color *tint, t_scene *scene)
{
	if (ft_double_len(scene->vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for color\n",
			scene, scene->vec_splitted);
	if (!only_digit_in_str(scene->vec_splitted[0]))
		exit_code(1, "R of color is invalid\n", scene, scene->vec_splitted);
	if (!only_digit_in_str(scene->vec_splitted[1]))
		exit_code(1, "G of color is invalid\n", scene, scene->vec_splitted);
	if (!only_digit_in_str(scene->vec_splitted[2]))
		exit_code(1, "B of color is invalid\n", scene, scene->vec_splitted);
	tint->r = ft_atof(scene->vec_splitted[0]);
	tint->g = ft_atof(scene->vec_splitted[1]);
	tint->b = ft_atof(scene->vec_splitted[2]);
	if (color_range_check(tint) == 0)
		exit_code(1, "Color coordinates are out of range\n",
			scene, scene->vec_splitted);
	if (scene->vec_splitted)
		double_free(scene->vec_splitted);
}

void	checker_a(char **splitted_a, t_scene *scene)
{
	float	ratio;
	t_color	color;
	int		len;

	ratio = 1;
	len = ft_double_len(splitted_a);
	if (len != 3)
		if (!(len == 4 && splitted_a[3][0] == '\n'))
			exit_code(1, "Invalid number of parameters for A\n",
				scene, splitted_a);
	ratio = ft_atof(splitted_a[1]);
	if (!only_digit_in_str(splitted_a[1]))
		exit_code(1, "ratio for A is invalid\n", scene, splitted_a);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for A\n", scene, splitted_a);
	scene->vec_splitted = ft_split(splitted_a[2], ',');
	check_color(&color, scene);
	scene->amb = init_ambient(ratio, color, scene);
}

void	checker_c(char **splitted_c, t_scene *scene)
{
	t_vec	origin_vec;
	t_vec	orient_vec;
	float	fov;
	int		len;

	len = ft_double_len(splitted_c);
	if (len != 4)
		if (!(len == 5 && splitted_c[4][0] == '\n'))
			exit_code(1, "Invalid parameters for C\n", scene, splitted_c);
	scene->vec_splitted = ft_split(splitted_c[1], ',');
	check_vector(&origin_vec, INT_MIN, FLT_MAX, scene);
	scene->vec_splitted = ft_split(splitted_c[2], ',');
	check_vector(&orient_vec, -8, 1, scene);
	fov = ft_atof(splitted_c[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_code(1, "fov is out of range for C\n", scene, splitted_c);
	scene->cam = init_cam(origin_vec, orient_vec, fov, scene);
}

void	checker_l(char **splitted_l, t_scene *scene)
{
	t_vec	origin_vec;
	float	ratio;
	t_color	color;
	int		len;

	len = ft_double_len(splitted_l);
	if (len != 4)
		if (!(len == 5 && splitted_l[4][0] == '\n'))
			exit_code(1, "Invalid parameters for l\n", scene, splitted_l);
	scene->vec_splitted = ft_split(splitted_l[1], ',');
	check_vector(&origin_vec, INT_MIN, FLT_MAX, scene);
	ratio = ft_atof(splitted_l[2]);
	if (!only_digit_in_str(splitted_l[2]))
		exit_code(1, "ratio for l is invalid\n", scene, splitted_l);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for l\n", scene, splitted_l);
	scene->vec_splitted = ft_split(splitted_l[3], ',');
	check_color(&color, scene);
	scene->light = initlight(origin_vec, ratio, color, scene);
}
