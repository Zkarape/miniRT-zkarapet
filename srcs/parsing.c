/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarapet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 18:14:05 by zkarapet          #+#    #+#             */
/*   Updated: 2023/07/10 18:14:06 by zkarapet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static char	**check_d_line(char *line)
{
	char	**splitted;

	splitted = ft_split_m(line);
	return (splitted);
}

void	once(int stat, t_scene *scene, char **splittedd,
		void (*checker)(char **splitted, t_scene *sc))
{
	if (stat != 1)
		exit_code(1, "Upper letters must be declared once\n", scene, NULL);
	checker(splittedd, scene);
}

int	checker_each_object(char **splitted_line, t_scene *scene)
{
	static int	a = 0;
	static int	c = 0;
	static int	l = 0;

	if (ft_strncmp(splitted_line[0], "A", 2) == 0 && ++a)
		once(a, scene, splitted_line, checker_a);
	else if (ft_strncmp(splitted_line[0], "C", 2) == 0 && ++c)
		once(c, scene, splitted_line, checker_c);
	else if (ft_strncmp(splitted_line[0], "L", 2) == 0 && ++l)
		once(l, scene, splitted_line, checker_l);
	else if (ft_strncmp(splitted_line[0], "pl", 3) == 0)
		checker_pl(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "sp", 3) == 0)
		checker_sp(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "cy", 3) == 0)
		checker_cy(splitted_line, scene);
	else
		exit_code(1, "Invalid argument\n", scene, NULL);
	return (a + c + l);
}

static void	reading_file(int fd, t_scene *scene)
{
	char	*line;
	char	**splitted;
	int		count;

	line = NULL;
	splitted = NULL;
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		splitted = check_d_line(line);
		if (line)
			free_null(line);
		if (splitted && splitted[0] && splitted[0][0] != '\n')
			count = checker_each_object(splitted, scene);
		if (splitted)
			double_free(splitted);
	}
	if (count != 3)
		exit_code(1, "Upper letters must be declared once\n", scene, NULL);
}

void	parsing(int argc, char **argv, t_scene *var_scene)
{
	int	fd;

	fd = 0;
	if (argc != 2)
	{
		if (argc == 1)
			exit_code(1, "No argument\n", NULL, NULL);
		else
			exit_code(1, "More arguments\n", NULL, NULL);
	}
	if (is_rt_file(argv[1]) == 0)
		exit_code(1, "file requires .rt extension\n", NULL, NULL);
	fd = open(argv[1], O_RDWR);
	if (fd < 0)
		exit_code(1, "error opening the file\n", NULL, NULL);
	reading_file(fd, var_scene);
}
