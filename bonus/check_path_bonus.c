/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:37:31 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/03 12:14:29 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	is_path_start(t_map *plan)
{
	int	**visited;
	int	i;
	int	j;

	visited = create_matrice(plan);
	i = 0;
	while (i < plan->height)
	{
		j = 0;
		while (j < plan->width)
		{
			if (plan->map[i][j] == 'P' && !visited[i][j])
			{
				if (backtracking_co(plan, i, j, visited))
				{
					free_matrice(visited, plan);
					return (1);
				}	
			}
			j++;
		}
		i++;
	}
	free_matrice(visited, plan);
	return (0);
}

int	is_safe(int i, int j, t_map *plan)
{
	if (i >= 0 && i < plan->height && j >= 0 && j < plan->width)
		return (1);
	return (0);
}

int	backtracking_ex(t_map *plan, int i, int j, int **visited)
{
	if (is_safe(i, j, plan) && plan->map[i][j] != '1' && !visited[i][j])
	{
		visited[i][j] = 1;
		if (plan->map[i][j] == 'E')
			return (1);
		if (backtracking_ex(plan, i - 1, j, visited))
			return (1);
		if (backtracking_ex(plan, i, j - 1, visited))
			return (1);
		if (backtracking_ex(plan, i + 1, j, visited))
			return (1);
		if (backtracking_ex(plan, i, j + 1, visited))
			return (1);
	}
	return (0);
}

int	backtracking_co(t_map *plan, int i, int j, int **visited)
{
	if (is_safe(i, j, plan) && plan->map[i][j] != '1' && !visited[i][j])
	{
		visited[i][j] = 1;
		if (plan->map[i][j] == 'C')
		{
			plan->map[i][j] = 'Z';
			return (1);
		}
		if (backtracking_co(plan, i - 1, j, visited))
			return (1);
		if (backtracking_co(plan, i, j - 1, visited))
			return (1);
		if (backtracking_co(plan, i + 1, j, visited))
			return (1);
		if (backtracking_co(plan, i, j + 1, visited))
			return (1);
	}
	return (0);
}

void	check_path(t_map *plan)
{
	int	collectibles;

	collectibles = plan->collectibles;
	while (collectibles)
	{
		if (!is_path_start(plan))
		{
			free_check(&plan);
			ft_printf("Error\nNo Valid Path\n");
			exit(2);
		}
		collectibles--;
	}
	if (!is_path_exit(plan))
	{
		free_check(&plan);
		ft_printf("Error\nNo Valid Path\n");
		exit(2);
	}
	reset_collect(plan);
}
