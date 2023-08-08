/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aivanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:53 by skeveyan          #+#    #+#             */
/*   Updated: 2023/06/03 03:07:52 by aivanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	chekin_n(char *s)
{
	size_t	n;

	n = 0;
	if (s)
	{
		while (s[n] && s[n] != '\n')
		n++;
		if (s[n] == '\n')
			return (0);
	}
	return (1);
}

void	freek(char **s)
{
	if (*s)
	{
		free(*s);
		(*s) = NULL;
	}
}
