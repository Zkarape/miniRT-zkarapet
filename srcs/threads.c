/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 21:19:19 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/10 21:19:25 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	calculate(t_all *all, int x, int y)
{
	t_cross			*final_cross;
	t_ray			ray;
	t_color			col;
	unsigned int	color;

	final_cross = NULL;
	ray = ray_generate(x, y, *(all->scene->cam));
	ray_trace(all->scene, ray, &final_cross);
	if (final_cross->t == INFINITY)
		color = (0 << 16 | 0 << 8 | 0);
	else
	{
		col = final_lighting(all->scene, final_cross);
		color = make_int_from_rgb(col);
	}
	free_null(final_cross);
	my_mlx_pixel_put(all->mlx_data, x, y, color);
}

void	*thread_width_function(void *data)
{
	t_all		*all;
	int			xy[2];

	all = data;
	xy[0] = all->x;
	all->check = 0;
	xy[1] = -1;
	while (++(xy[1]) < HEIGHT)
		calculate(all, xy[0], xy[1]);
	pthread_exit (NULL);
}

void	render(t_all *all)
{
	int			result_w;
	int			count_treads;
	int			cycle;
	pthread_t	threads[WIDTH];

	result_w = 0;
	cycle = 0;
	count_treads = 0;
	all->x = -1;
	while (++(all->x) < WIDTH)
	{
		all->check = 1;
		result_w = pthread_create(&threads[count_treads++],
				NULL, thread_width_function, all);
		if (result_w != 0)
			exit_code(1, "Thread creation failed", all->scene, NULL);
		while (all->check)
			;
	}
	while (cycle < WIDTH)
		pthread_join(threads[cycle++], NULL);
	mlx_put_image_to_window(all->mlx_data->mlx, all->mlx_data->win,
		all->mlx_data->img, 0, 0);
	return ;
}
