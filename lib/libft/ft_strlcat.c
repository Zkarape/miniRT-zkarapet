/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 15:44:55 by skeveyan          #+#    #+#             */
/*   Updated: 2022/04/02 15:45:09 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lensrc ;
	size_t	lendest ;
	size_t	n ;
	size_t	t ;

	lensrc = ft_strlen(src);
	lendest = ft_strlen(dst);
	n = 0;
	if (dstsize < 1 || dstsize < lendest)
		return (lensrc + dstsize);
	t = lendest;
	while (src[n] && t < dstsize - 1)
			dst[t++] = src[n++];
		dst[lendest + n] = '\0';
	return (lendest + lensrc);
}
