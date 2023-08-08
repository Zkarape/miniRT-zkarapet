/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:29:28 by skeveyan          #+#    #+#             */
/*   Updated: 2022/11/05 17:27:48 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	chek_plus_minus( const char **str, int *minus_counter)
{
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*minus_counter = -1;
		(*str)++;
		if (!(**str >= '0' && **str <= '9'))
		{
			write (1, "non correct input\n", 17);
			exit(0);
		}
	}
}

long int	ft_atoi(const char *str)
{
	long int	res;
	int			minus_counter;

	res = 0;
	minus_counter = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		||*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	chek_plus_minus(&str, &minus_counter);
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = (res * 10) +(*str - '0');
		str++;
	}
	if (!(*str))
		return (res * minus_counter);
	write (1, "non correct input\n", 17);
	exit(0);
}
