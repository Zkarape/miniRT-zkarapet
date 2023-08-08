/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frik.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <aivanyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:41:56 by skeveyan          #+#    #+#             */
/*   Updated: 2023/07/07 02:27:38 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	double_free(char **s1)
{
	int	i;

	i = 0;
	if (s1 && s1 != NULL)
	{
		while (s1[i])
		{
			free(s1[i]);
			s1[i++] = NULL;
		}
		free(s1);
		s1 = NULL;
	}
}

void	free_null(void *s)
{
	if (s)
		free(s);
	s = NULL;
}
