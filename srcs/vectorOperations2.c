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

t_vec	vec_scale(float n, t_vec p)
{
	t_vec	v;

	v.x = n * p.x;
	v.y = n * p.y;
	v.z = n * p.z;
	return (v);
}

float	distance(t_vec p1, t_vec p2)
{
	return (sqrt(pow(p2.x - p1.x, 2)
			+ pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2)));
}

float	vec_norm(t_vec vec)
{
	float	norm;

	norm = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (norm);
}

t_vec	vec_mul(t_vec v, float f)
{
	t_vec	vec;

	vec.x = v.x * f;
	vec.y = v.y * f;
	vec.z = v.z * f;
	return (vec);
}

t_vec	vec_inverse(t_vec v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}
