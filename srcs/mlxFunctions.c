/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxFunctions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:12:44 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:12:45 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_mlx *data, double x, double y, unsigned int color)
{
	int		memory_offset;
	char	*get_data;

	memory_offset = y * data->line_length + x * (data->bpp / 8);
	get_data = data->addr + memory_offset;
	*(unsigned int *)get_data = color;
}

void	mlx_data_init(t_mlx *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->win = mlx_new_window(mlx_data->mlx, WIDTH, HEIGHT, "miniRT");
	mlx_data->img = mlx_new_image(mlx_data->mlx, WIDTH, HEIGHT);
	mlx_data->addr = mlx_get_data_addr(mlx_data->img, &mlx_data->bpp,
			&mlx_data->line_length, &mlx_data->endian);
}
