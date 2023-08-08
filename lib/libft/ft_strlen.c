/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:40:07 by skeveyan          #+#    #+#             */
/*   Updated: 2023/03/05 14:12:27 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	if (!s)
		return (n);
	while (s[n])
		n++;
	return (n);
}

int	ft_strlen_1(const char *s)
{
	int	n;

	n = 0;
	if (!s && !(*s))
		return (n);
	while (s[n])
		n++;
	return (n);
}
