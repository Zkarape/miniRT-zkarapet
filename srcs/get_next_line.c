/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skeveyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 22:38:04 by skeveyan          #+#    #+#             */
/*   Updated: 2022/08/12 18:16:02 by skeveyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*returnline;
	static char	*temporary;
	size_t		i_return;
	long int	read_value;

	read_value = 1;
	i_return = 0;
	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE >= UINT32_MAX || read(fd, 0, 0) < 0)
		return (NULL);
	if ((read_chek(fd, &temporary, &read_value)))
		return (NULL);
	if (0 > (write_return(&temporary, &returnline, &i_return)))
		return (NULL);
	if (!(take_temporary(&temporary, &i_return)))
		return (returnline);
	return (NULL);
}

int	read_chek(int fd, char **temporary, long int *read_value)
{
	char		*readback;
	char		*box;

	readback = (char *) malloc(BUFFER_SIZE + 1);
	if (!readback)
		return (1);
	while ((chekin_n(*temporary)) && *read_value)
	{
		*read_value = read(fd, readback, BUFFER_SIZE);
		if (*read_value < 0)
			return (1);
		if (*read_value)
		{	
			readback[*read_value] = '\0';
			box = ft_strdup(*temporary);
			if (*temporary)
				freek(temporary);
			(*temporary) = ft_strjoin(box, readback);
			if (box)
				freek(&box);
		}
	}
	if (readback)
		freek(&readback);
	return (0);
}

int	write_return(char **temporary, char **returnline, size_t *i_return)
{
	if ((*temporary))
	{
		while ((*temporary)[(*i_return)] != '\n' && (*temporary)[(*i_return)])
			(*i_return)++;
		if ((*temporary)[(*i_return)] == '\n' && (*temporary)[(*i_return)])
			(*i_return)++;
		(*returnline) = (char *)malloc((*i_return) + 1);
		if (!(*returnline))
			return (-1);
		(*i_return) = 0;
		while ((*temporary)[(*i_return)] && (*temporary)[(*i_return)] != '\n')
		{
			(*returnline)[(*i_return)] = (*temporary)[(*i_return)];
			(*i_return)++;
		}
		if ((*temporary)[(*i_return)] == '\n')
		{
			(*returnline)[(*i_return)++] = '\n';
			(*returnline)[(*i_return)] = '\0';
		}
		else
			(*returnline)[(*i_return)] = '\0';
		return (*i_return);
	}
	return (-2);
}

int	take_temporary(char **temporary, size_t *i_return)
{
	size_t	t;
	char	*box;

	t = 0;
	if ((*temporary) && ((*temporary)[*i_return]))
	{
		box = ft_strdup((*temporary));
		free(*temporary);
		*temporary = NULL;
		(*temporary) = (char *) malloc(ft_strlen((box)) - (*i_return) + 1);
		if (!(*temporary))
			return (1);
		while (box[*i_return] != '\0')
			(*temporary)[t++] = box[(*i_return)++];
		(*temporary)[t] = '\0';
		if (box)
		{
			free(box);
			box = NULL;
		}
	}
	else
		freek(temporary);
	return (0);
}
