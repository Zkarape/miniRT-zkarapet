/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:12:18 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:12:20 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	clos(t_scene *scene)
{
	exit_code(0, "finish\n", scene, NULL);
	return (0);
}

int	camera_direction(int code, t_all *all)
{
	int	k;

	k = 5;
	if (code == 65362 || code == 126)
		all->scene->light->orig.y = all->scene->light->orig.y + k;
	else if (code == 65364 || code == 125)
		all->scene->light->orig.y = all->scene->light->orig.y - k;
	else if (code == 65361 || code == 123)
		all->scene->light->orig.x = all->scene->light->orig.x + k;
	else if (code == 65363 || code == 124)
		all->scene->light->orig.x = all->scene->light->orig.x - k;
	else if (code == 65436)
		all->scene->light->orig.z = all->scene->light->orig.z + k;
	else if (code == 65438)
		all->scene->light->orig.z = all->scene->light->orig.z - k;
	render(all);
	return (0);
}

int	key_hook_man(int code, t_all *all)
{
	int	k;

	k = 5;
	if (code == 65307 || code == 53)
		exit_code(0, "finish_esc\n", NULL, NULL);
	else if (code == 119 || code == 13)
		all->scene->cam->orig.y = all->scene->cam->orig.y + k;
	else if (code == 115 || code == 1)
		all->scene->cam->orig.y = all->scene->cam->orig.y - k;
	else if (code == 97 || code == 0)
		all->scene->cam->orig.x = all->scene->cam->orig.x + k;
	else if (code == 100 || code == 2)
		all->scene->cam->orig.x = all->scene->cam->orig.x - k;
	else if (code == 113)
		all->scene->cam->orig.z = all->scene->cam->orig.z + k;
	else if (code == 101)
		all->scene->cam->orig.z = all->scene->cam->orig.z - k;
	camera_direction(code, all);
	return (0);
}

int	main(int argc, char **argv)
{
	t_scene	scene;
	t_mlx	mlx_data;
	t_all	all;

	all.scene = &scene;
	all.mlx_data = &mlx_data;
	init_scene(&scene);
	mlx_data_init(&mlx_data);
	parsing(argc, argv, &scene);
	mlx_key_hook(mlx_data.win, key_hook_man, &all);
	mlx_hook(mlx_data.win, 17, 0, clos, &scene);
	render(&all);
	mlx_loop(mlx_data.mlx);
	free_scene(&scene);
	return (0);
}
