/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artadevo <artadevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:30:36 by skeveyan          #+#    #+#             */
/*   Updated: 2023/01/27 15:31:35 by artadevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	n;

	n = 0;
	if (ft_strlen(s) < start)
	{	
		new_str = malloc (sizeof(char));
		new_str[n] = '\0';
		return (new_str);
	}
	while (s[n] && n < len)
		n++;
	new_str = (char *)malloc(n + 1);
	if (!s || !new_str)
		return (0);
	n = 0;
	while (s[start + n] && n < len)
	{
		new_str[n] = s[start + n];
		n++;
	}
	new_str[n++] = '\0';
	return (new_str);
}
