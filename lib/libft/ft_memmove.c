/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:33:47 by skeveyan          #+#    #+#             */
/*   Updated: 2022/03/31 10:44:49 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	unsigned const char	*srcuse;
	unsigned char		*dstuse;

	srcuse = src;
	dstuse = dst;
	if (dstuse > srcuse)
		while (len--)
			dstuse[len] = srcuse[len];
	else
		while (len--)
			*dstuse++ = *srcuse++;
	return (dst);
}
