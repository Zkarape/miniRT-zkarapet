/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphereOperations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:15:15 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:15:17 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_sphere	*ft_lstlast_sp(t_sphere *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new)
{
	t_sphere	*position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast_sp(*lst);
		position->next = new;
	}
}

static t_sphere	*init_sphere(t_vec orig, t_color col, float rad, t_scene *scene)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_code(1, "sphere malloc failed", scene, NULL);
	init_vector(orig, &(sphere->center));
	init_color(col, &(sphere->tint));
	sphere->radius = rad;
	sphere->next = NULL;
	return (sphere);
}

void	checker_sp(char **splitted_sp, t_scene *scene)
{
	t_vec	center_vec;
	t_color	tint_vec;
	float	radius;
	int		len;

	len = ft_double_len(splitted_sp);
	if (len != 4)
		if (!(len == 5 && splitted_sp[4][0] == '\n'))
			exit_code(1, "Invalid number of parameters for sp\n", scene, NULL);
	scene->vec_splitted = ft_split(splitted_sp[1], ',');
	check_vector(&center_vec, INT_MIN, FLT_MAX, scene);
	scene->vec_splitted = ft_split(splitted_sp[3], ',');
	check_color(&tint_vec, scene);
	radius = ft_atof(splitted_sp[2]);
	if (!scene->sphere)
		scene->sphere = init_sphere(center_vec, tint_vec, radius, scene);
	else
		ft_lstadd_back_sp(&scene->sphere, init_sphere(center_vec,
				tint_vec, radius, scene));
}
