/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:15:55 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:15:56 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	is_rt_file(char *path)
{
	int	len;

	len = ft_strlen(path) - 3;
	if (len > 0)
		return (ft_strncmp(path + len, ".rt", 3) == 0);
	return (0);
}

float	find_min(float a, float b, float c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b <= c)
		return (b);
	else if (c < a && c < b)
		return (c);
	else
		return (INFINITY);
}

unsigned int	make_int_from_rgb(t_color color)
{
	int	r;
	int	g;
	int	b;

	r = (double)(color.r * 255);
	g = (double)(color.g * 255);
	b = (double)(color.b * 255);
	return (r << 16 | g << 8 | b);
}

t_color	col_mul(t_color a, t_color b)
{
	t_color	c;

	c.r = a.r * b.r;
	c.g = a.g * b.g;
	c.b = a.b * b.b;
	return (c);
}

void	init_scene(t_scene *scene)
{
	scene->amb = NULL;
	scene->cam = NULL;
	scene->light = NULL;
	scene->sphere = NULL;
	scene->begin_sphere = NULL;
	scene->plane = NULL;
	scene->begin_plane = NULL;
	scene->cylin = NULL;
	scene->begin_cylinder = NULL;
}
