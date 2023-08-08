/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:11:37 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/11 17:11:59 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= SIZE_MAX || size >= SIZE_MAX || (count * size) >= SIZE_MAX)
		return (0);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', size * count);
	return (ptr);
}
