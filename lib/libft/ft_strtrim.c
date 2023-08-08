/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:00:44 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/12 22:38:38 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		size;
	size_t		startindex;

	startindex = 0;
	size = ft_strlen(s1) - 1;
	while (s1[startindex] && ft_strchr(set, s1[startindex]))
		startindex++;
	while (0 < size - startindex && ft_strchr (set, s1[size]))
		size--;
	str = ft_substr(s1 + startindex, 0, (size - startindex + 1));
	return (str);
}
