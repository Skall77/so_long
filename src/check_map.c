/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 18:54:30 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/26 17:26:21 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(t_map *plan)
{
	if (rectangle_map(plan) == 0)
	{
		free_check(&plan);
		ft_printf("Error\nMap isn't a rectangle\n");
		exit(2);
	}
	if (check_wall(plan) == 0)
	{
		free_check(&plan);
		ft_printf("Error\nWalls are wrong\n");
		exit(2);
	}
	if (check_characters(plan) == 0)
	{
		free_check(&plan);
		ft_printf("Error\nINTRUDER !!\n");
		exit(2);
	}
	check_rest(plan);
}

int	rectangle_map(t_map *plan)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (plan->map[0][i])
		i++;
	size = i;
	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
			j++;
		if (size != j)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall(t_map *plan)
{
	int	i;

	i = 0;
	while (plan->map[0][i])
	{
		if (plan->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < plan->height)
	{
		if (plan->map[i][0] != '1' || plan->map[i][plan->width - 1] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (plan->map[plan->height - 1][i])
	{
		if (plan->map[plan->height - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_characters(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'C')
				plan->collectibles++;
			else if (plan->map[i][j] == 'E')
				plan->exit++;
			else if (plan->map[i][j] == 'P')
				plan->sp++;
			else if (plan->map[i][j] != '1' && plan->map[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_rest(t_map *plan)
{
	if (plan->collectibles < 1)
	{
		free_check(&plan);
		ft_printf("Error\nNothing to collect\n");
		exit(2);
	}
	if (plan->sp != 1)
	{
		free_check(&plan);
		ft_printf("Error\nWhere do I start ?\n");
		exit(2);
	}
	if (plan->exit != 1)
	{
		free_check(&plan);
		ft_printf("Error\nWhere do I leave ?\n");
		exit(2);
	}
}
