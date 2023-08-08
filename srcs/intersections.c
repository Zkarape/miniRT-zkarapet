/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:39 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:09:41 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	fill_sphere_cross(t_cross *cross, float t1)
{
	if (cross->t > t1)
		swap(&cross->t, &t1);
	if (cross->t < 0)
	{
		cross->t = t1;
		if (cross->t < 0)
			return (false);
	}
	return (true);
}

bool	intersect_sphere(t_ray ray, t_sphere sphere, t_cross *cross)
{
	float	tohdot;
	float	thc;
	float	d_square;
	float	t1;
	t_vec	l;

	l = vec_sub(sphere.center, ray.orig);
	tohdot = dot_product(l, ray.dir);
	if (tohdot < 0)
		return (false);
	d_square = dot_product(l, l) - tohdot * tohdot;
	if (d_square > sphere.radius * sphere.radius)
		return (false);
	thc = sqrt(sphere.radius * sphere.radius - d_square);
	cross->t = tohdot - thc;
	t1 = tohdot + thc;
	if (!fill_sphere_cross(cross, t1))
		return (false);
	point_calc(&cross->p, ray, cross->t);
	cross->n = sphere_normal(cross->p, sphere.center);
	cross->color = sphere.tint;
	return (true);
}

bool	intersect_plane(t_ray ray, t_plane plane, t_cross *cross)
{
	float	denominator;
	t_vec	dot;

	denominator = dot_product(plane.normal, ray.dir);
	dot = vec_sub(plane.point, ray.orig);
	if (denominator == 0)
		return (false);
	cross->t = (dot_product(dot, plane.normal)) / denominator;
	if (cross->t < EPSILON)
		return (false);
	cross->n = plane.normal;
	if (dot_product(plane.normal, ray.dir) > 0)
		cross->n = vec_inverse(cross->n);
	point_calc(&cross->p, ray, cross->t);
	cross->color = plane.tint;
	return (true);
}
