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

t_vec	sphere_normal(t_vec p, t_vec center)
{
	return (normalize(vec_sub(p, center)));
}

t_vec	top_cap_center(t_cylinder cyl)
{
	t_vec	top;

	top = vec_scale(-0.5 * cyl.height, cyl.axis);
	top = vec_add(cyl.center, top);
	return (top);
}

t_vec	bottom_cap_center(t_cylinder cyl)
{
	t_vec	btm;

	btm = vec_scale(0.5 * cyl.height, cyl.axis);
	btm = vec_add(btm, cyl.center);
	return (btm);
}

t_vec	cylinder_normal(t_cylinder cylin, t_cross cross, float m)
{
	t_vec	norm;

	norm = normalize(vec_sub(vec_sub(cross.p,
					top_cap_center(cylin)), vec_scale(m, cylin.axis)));
	return (norm);
}
