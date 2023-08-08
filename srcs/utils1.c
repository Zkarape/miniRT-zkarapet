/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:15:46 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:15:48 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	atof_check(char *str, float *result, float fraction)
{
	str++;
	while (ft_isdigit(*str))
	{
		*result += (*str - '0') * fraction;
		fraction /= 10.0;
		str++;
	}
}

float	ft_atof(char *str)
{
	float	result;
	float	sign;
	float	fraction;

	result = 0.0;
	sign = 1;
	fraction = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
		atof_check(str, &result, fraction);
	return (result * sign);
}

int	ft_double_len(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
		;
	return (i);
}

bool	is_in_range_check(float number, float lower, float upper)
{
	if (number >= lower && number <= upper)
		return (true);
	return (false);
}

void	swap(float	*a, float *b)
{
	float	c;

	c = *a;
	*a = *b;
	*b = c;
}
