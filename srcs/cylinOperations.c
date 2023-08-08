/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinOperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:08:24 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:08:25 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cylinder	*ft_lstlast_cylin(t_cylinder *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast_cylin(*lst);
		position->next = new;
	}
}

t_cylinder	*init_cylinder(t_vec center, t_vec normal, t_color tint, char **cy)
{
	t_cylinder	*cylinder;

	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit_code(1, "cylinder malloc failed", NULL, NULL);
	init_vector(center, &(cylinder->center));
	init_vector(normal, &(cylinder->axis));
	init_color(tint, &(cylinder->tint));
	cylinder->radius = ft_atof(cy[3]) / 2;
	cylinder->height = ft_atof(cy[4]);
	cylinder->top_cap_cent = top_cap_center(*cylinder);
	cylinder->bottom_cap_cent = bottom_cap_center(*cylinder);
	cylinder->next = NULL;
	return (cylinder);
}

void	checker_cy(char **cy, t_scene *scene)
{
	t_vec	origin_vec;
	t_vec	orient_vec;
	t_color	tint_vec;
	int		len;

	len = ft_double_len(cy);
	if (len != 6)
		if (!(len == 7 && cy[6][0] == '\n'))
			exit_code(1, "Invalid parameters for cylin\n", scene, NULL);
	scene->vec_splitted = ft_split(cy[1], ',');
	check_vector(&origin_vec, INT_MIN, FLT_MAX, scene);
	scene->vec_splitted = ft_split(cy[2], ',');
	check_vector(&orient_vec, -8, 1, scene);
	scene->vec_splitted = ft_split(cy[5], ',');
	check_color(&tint_vec, scene);
	if (!scene->cylin)
		scene->cylin = init_cylinder(origin_vec, orient_vec, tint_vec, cy);
	else
		ft_lstadd_back_cy(&scene->cylin,
			init_cylinder(origin_vec, orient_vec, tint_vec, cy));
}
