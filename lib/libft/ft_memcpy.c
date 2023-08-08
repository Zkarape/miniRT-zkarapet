/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:48:30 by skeveyan          #+#    #+#             */
/*   Updated: 2022/03/31 10:48:52 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned const char	*srcuse;
	unsigned char		*dstuse;

	srcuse = src;
	dstuse = dst;
	while (n--)
	{
		*dstuse = *srcuse;
		dstuse++;
		srcuse++;
	}
	return (dst);
}
