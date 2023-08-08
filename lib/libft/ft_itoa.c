/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:17:16 by skeveyan          #+#    #+#             */
/*   Updated: 2022/05/20 19:17:21 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	unsigned int	nbr;
	int				i;

	i = 1;
	if (n < 0)
	{
		nbr = -n;
		i++;
	}
	else
		nbr = n;
	while (nbr / 10 > 0)
	{
		i++;
		nbr = nbr / 10;
	}
	return (i);
}

char	*loop(unsigned int nb, size_t size, char *str)
{
	while (nb != 0)
	{
		str[size--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t			size;
	unsigned int	nb;
	char			*str;

	nb = n;
	size = ft_count(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (n < 0)
	{
		nb = -n;
		*str = '-';
	}
	str[size--] = '\0';
	loop(nb, size, str);
	return (str);
}
