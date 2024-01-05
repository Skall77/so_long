/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plan_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:26:42 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/03 12:14:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_plan(t_map **plan)
{
	*plan = malloc(sizeof(t_map));
	if (!plan)
		leave_error("Error\nBad Malloc\n", plan);
	(*plan)->map = NULL;
	(*plan)->hero.x = 0;
	(*plan)->hero.y = 0;
	(*plan)->height = 0;
	(*plan)->width = 0;
	(*plan)->collectibles = 0;
	(*plan)->exit = 0;
	(*plan)->sp = 0;
	(*plan)->moves = 0;
}

void	size_map(t_map *plan, char **argv)
{
	char	*line;
	int		fd;
	size_t	size;
	int		height;

	height = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		leave_error("Error\nproblem with open()\n", &plan);
	line = get_next_line(fd);
	if (!line)
		leave_error("Error\nBad Malloc\n", &plan);
	size = ft_strlen(line) - 1;
	while (line)
	{
		height++;
		if (ft_strlen(line) > size)
			size = ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	plan->height = height;
	plan->width = (int)size;
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	ft_printf("\n");
}

void	free_map(char **map, t_map *plan, int fd, char *line)
{
	int	i;

	i = 0;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
	}
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	close(fd);
	leave_error("Error\nBad Malloc\n", &plan);
}

void	parse_map(t_map *plan, char **argv)
{
	int		fd;
	char	**map;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		leave_error("Error\nproblem with open()\n", &plan);
	map = malloc(sizeof(char *) * (plan->height + 1));
	if (!map)
	{
		close(fd);
		leave_error("Error\nBad Malloc\n", &plan);
	}
	map[plan->height] = NULL;
	get_map(plan, map, fd);
	close(fd);
	i = 0;
	while (map[0][i])
		i++;
	plan->width = i;
	plan->map = map;
}
