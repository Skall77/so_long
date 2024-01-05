/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:57:26 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/03 16:30:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	build_map(t_map *plan, char **map, int i, char *line)
{
	int	j;

	j = 0;
	while (j < plan->width && line[j] != '\n' && line[j])
	{
		map[i][j] = line[j];
		j++;
	}
	map[i][j] = '\0';
}

void	get_map(t_map *plan, char **map, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	if (!line)
		free_map(map, plan, fd, line);
	while (i < plan->height)
	{
		map[i] = malloc(sizeof(char) * (plan->width + 1));
		if (!map[i])
			free_map(map, plan, fd, line);
		build_map(plan, map, i, line);
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		i++;
	}
}
