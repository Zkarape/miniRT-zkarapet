/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 22:54:27 by aivanyan          #+#    #+#             */
/*   Updated: 2023/07/10 11:43:44 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_vector(t_vec vector, t_vec *objVect)
{
	(*objVect).x = vector.x;
	(*objVect).y = vector.y;
	(*objVect).z = vector.z;
}

void	init_color(t_color tint, t_color *ambTint)
{
	(*ambTint).r = tint.r / 255;
	(*ambTint).g = tint.g / 255;
	(*ambTint).b = tint.b / 255;
}

t_ambient	*init_ambient(float ratio, t_color tint, t_scene *scene)
{
	t_ambient	*amb;

	amb = malloc(sizeof(t_ambient));
	if (!amb)
		exit_code(1, "ambient malloc failed", scene, NULL);
	init_color(tint, &(amb->tint));
	amb->ratio = ratio;
	return (amb);
}

t_cam	*init_cam(t_vec origin, t_vec orient, float fov, t_scene *scene)
{
	t_cam	*camera;

	camera = malloc(sizeof(t_cam));
	if (!camera)
		exit_code(1, "camera malloc failed", scene, NULL);
	init_vector(origin, &(camera->orig));
	init_vector(orient, &(camera->orientation));
	camera->fov = fov;
	return (camera);
}

t_light	*initlight(t_vec orig, float ratio, t_color tint, t_scene *scene)
{
	t_light	*light;

	light = malloc(sizeof(t_light));
	if (!light)
		exit_code(1, "origin malloc failed", scene, NULL);
	init_vector(orig, &(light->orig));
	init_color(tint, &(light->tint));
	light->ratio = ratio;
	return (light);
}
