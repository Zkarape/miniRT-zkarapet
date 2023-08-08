/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LookAt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:11:15 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:11:16 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_vec	vec_init(float x, float y, float z)
{
	t_vec	tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;
	return (tmp);
}

void	look_at(t_matrix *matrix, t_cam camera)
{
	t_vec	arbitrary;

	arbitrary = vec_init(0, 1, 0);
	matrix->forward = normalize(camera.orientation);
	matrix->right = normalize(cross(arbitrary, matrix->forward));
	matrix->up = normalize(cross(matrix->forward, matrix->right));
}
