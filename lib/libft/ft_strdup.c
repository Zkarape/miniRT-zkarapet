/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:16:08 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/11 19:16:11 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*str;

	n = 0;
	if (!s)
		return (NULL);
	str = (char *) malloc(ft_strlen (s) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (*s)
		str[n++] = *s++;
	str[n] = '\0';
	return (str);
}
