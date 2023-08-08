/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planeOperations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:14:18 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:14:19 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_plane	*ft_lstlast_pl(t_plane *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_pl(t_plane **lst, t_plane *new)
{
	t_plane	*position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast_pl(*lst);
		position->next = new;
	}
}

static t_plane	*init_plane(t_vec point, t_vec normal, t_color col, t_scene *sc)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		exit_code(1, "plane malloc failed", sc, NULL);
	init_vector(point, &(plane->point));
	init_vector(normal, &(plane->normal));
	init_color(col, &(plane->tint));
	plane->next = NULL;
	return (plane);
}

void	checker_pl(char **splitted_pl, t_scene *scene)
{
	t_vec	origin_vec;
	t_vec	orient_vec;
	t_color	tint;
	int		len;

	len = ft_double_len(splitted_pl);
	if (len != 4)
		if (!(len == 5 && splitted_pl[4][0] == '\n'))
			exit_code(1, "Invalid number of parameters for pl\n", scene, NULL);
	scene->vec_splitted = ft_split(splitted_pl[1], ',');
	check_vector(&origin_vec, INT_MIN, FLT_MAX, scene);
	scene->vec_splitted = ft_split(splitted_pl[2], ',');
	check_vector(&orient_vec, -8, 1, scene);
	scene->vec_splitted = ft_split(splitted_pl[3], ',');
	check_color(&tint, scene);
	if (!scene->plane)
		scene->plane = init_plane(origin_vec, orient_vec, tint, scene);
	else
		ft_lstadd_back_pl(&scene->plane,
			init_plane(origin_vec, orient_vec, tint, scene));
}
