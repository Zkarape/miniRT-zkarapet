/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:51:31 by aivanyan          #+#    #+#             */
/*   Updated: 2023/07/10 12:42:43 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	ambient_lighting(t_ambient *ambient)
{
	return (color_mul(ambient->tint, ambient->ratio));
}

t_color	diffuse_lighting(t_light *light, t_cross *cross)
{
	t_vec	light_ray;
	float	dot;
	t_color	color;

	light_ray = normalize(vec_sub(light->orig, cross->p));
	dot = dot_product(light_ray, cross->n);
	if (dot < 0)
		dot = 0;
	color = color_mul(light->tint, light->ratio * dot);
	return (color);
}

t_color	specular_lightning(t_scene *scene, t_cross *cross)
{
	t_vec	light_ray;
	t_vec	reflect_ray;
	t_vec	view_ray;
	float	dot;
	t_color	col;

	light_ray = normalize(vec_sub(cross->p, scene->light->orig));
	reflect_ray = reflect_vec(light_ray, cross->n);
	view_ray = normalize(vec_sub(scene->cam->orig, cross->p));
	dot = dot_product(view_ray, reflect_ray);
	if (dot < 0)
		dot = 0;
	dot = pow(dot, SHININESS);
	col = color_mul(scene->light->tint, dot * STRENGTH);
	return (col);
}

bool	shadow(t_cross *cross, t_scene *scene)
{
	t_ray	shadow_ray;
	t_cross	*sdw_cross;

	sdw_cross = malloc(sizeof(t_cross));
	shadow_ray.orig = cross->p;
	shadow_ray.dir = normalize(vec_sub(scene->light->orig, cross->p));
	point_calc(&shadow_ray.orig, shadow_ray, 1);
	if (ray_trace(scene, shadow_ray, &sdw_cross)
		&& (distance(cross->p, scene->light->orig)
			> distance(cross->p, sdw_cross->p)))
	{
		free(sdw_cross);
		return (true);
	}
	free(sdw_cross);
	return (false);
}

t_color	final_lighting(t_scene *scene, t_cross *cross)
{
	t_color	amb_factor;
	t_color	diffuse;
	t_color	specular;

	amb_factor = ambient_lighting(scene->amb);
	if (!shadow(cross, scene))
	{
		diffuse = diffuse_lighting(scene->light, cross);
		specular = specular_lightning(scene, cross);
		cross->color = final_color(cross, amb_factor, diffuse, specular);
	}
	else
		cross->color = col_mul(amb_factor, cross->color);
	return (cross->color);
}
