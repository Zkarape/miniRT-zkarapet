/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:08:33 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:08:34 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"minirt.h"

void	exit_code(int code, char *msg, t_scene *scene, char **string)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	if (string)
		double_free(string);
	if (scene)
		free_scene(scene);
	exit(code);
}
