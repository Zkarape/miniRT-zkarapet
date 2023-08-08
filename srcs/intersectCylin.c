/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersectCylin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:09:03 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:09:04 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	solve_quadratic(t_quadratic *q)
{
	q->delta = q->b * q->b - 4 * q->a * q->c;
	if (q->delta < 0)
		return (false);
	q->t1 = (-q->b - sqrt(q->delta)) / (q->a * 2);
	q->t2 = (-q->b + sqrt(q->delta)) / (q->a * 2);
	return (true);
}

void	fill_quadratic(t_quadratic *q, t_ray ray, t_vec x, t_cylinder cylin)
{
	q->a = dot_product(ray.dir, ray.dir)
		- pow(dot_product(ray.dir, cylin.axis), 2);
	q->c = dot_product(x, x)
		- pow(dot_product(x, cylin.axis), 2) - cylin.radius * cylin.radius;
	q->b = 2 * (dot_product(ray.dir, x)
			- dot_product(ray.dir, cylin.axis) * dot_product(x, cylin.axis));
}

bool	intersect_infinite_cylin(t_ray ray, t_cylinder cylin, t_cross *cross)
{
	t_quadratic	q;
	t_vec		x;
	float		m;

	cylin.top_cap_cent = top_cap_center(cylin);
	x = vec_sub(ray.orig, cylin.top_cap_cent);
	fill_quadratic(&q, ray, x, cylin);
	if (!solve_quadratic(&q) || (q.t2 <= EPSILON && q.t1 <= EPSILON))
		return (false);
	if (q.t1 <= EPSILON || (q.t2 > EPSILON && (q.t2 < q.t1)))
		q.t1 = q.t2;
	if (cross->t < 0)
		return (false);
	cross->t = q.t1;
	m = dot_product(ray.dir, cylin.axis)
		* cross->t + dot_product(x, cylin.axis);
	if (m < 0 || m > cylin.height)
		return (false);
	point_calc(&cross->p, ray, cross->t);
	cross->n = cylinder_normal(cylin, *cross, m);
	cross->color = cylin.tint;
	return (true);
}

void	cap_check(t_cross cross_pl, t_cylinder cylin, float *t, t_cross *tmp)
{
	if (distance(cross_pl.p, cylin.top_cap_cent)
		<= cylin.radius && cross_pl.t < *t)
	{
		*tmp = cross_pl;
		*t = cross_pl.t;
	}
}

bool	intersect_cylin(t_ray ray, t_cylinder cylin, t_cross *cross)
{
	t_plane	plane;
	t_cross	cross_pl;
	t_cross	tmp;
	float	t;

	t = INFINITY;
	plane.point = cylin.top_cap_cent;
	plane.normal = cylin.axis;
	plane.tint = cylin.tint;
	if (intersect_plane(ray, plane, &cross_pl))
		cap_check(cross_pl, cylin, &t, &tmp);
	plane.point = cylin.bottom_cap_cent;
	if (intersect_plane(ray, plane, &cross_pl))
		cap_check(cross_pl, cylin, &t, &tmp);
	if (intersect_infinite_cylin(ray, cylin, cross) && cross->t < t)
		if (pow(distance(cylin.center, cross->p), 2)
			<= pow(cylin.height * 0.5, 2) + cylin.radius * cylin.radius)
			tmp = *cross;
	*cross = tmp;
	return (cross->t < INFINITY && cross->t > EPSILON);
}
