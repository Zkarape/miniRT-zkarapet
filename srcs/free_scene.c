/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:09:34 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/07 02:26:24 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_sphere(t_sphere *spher)
{
	t_sphere	*boxs;

	boxs = NULL;
	while (spher)
	{
		boxs = spher->next;
		free_null(spher);
		spher = boxs;
	}
}

static void	free_plane(t_plane *plane)
{
	t_plane	*boxs;

	boxs = NULL;
	while (plane)
	{
		boxs = plane->next;
		free_null(plane);
		plane = boxs;
	}
}

static void	free_cylin(t_cylinder *cylin)
{
	t_cylinder	*boxs;

	boxs = NULL;
	while (cylin)
	{
		boxs = cylin->next;
		free_null(cylin);
		cylin = boxs;
	}
}

void	free_scene(t_scene *s)
{
	if (s->amb)
		free_null(s->amb);
	if (s->cam)
		free_null(s->cam);
	if (s->light)
		free_null(s->light);
	if (s->sphere)
		free_sphere(s->sphere);
	if (s->begin_sphere)
		free_sphere(s->begin_sphere);
	if (s->plane)
		free_plane(s->plane);
	if (s->begin_plane)
		free_plane(s->begin_plane);
	if (s->cylin)
		free_cylin(s->cylin);
	if (s->begin_cylinder)
		free_cylin(s->begin_cylinder);
}
