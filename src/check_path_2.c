/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:07:52 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/20 11:15:26 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_path_exit(t_map *plan)
{
	int	**visited;
	int	i;
	int	j;

	i = 0;
	visited = create_matrice(plan);
	while (i < plan->height)
	{
		j = 0;
		while (j < plan->width)
		{
			if (plan->map[i][j] == 'P' && !visited[i][j])
			{
				if (backtracking_ex(plan, i, j, visited))
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

void	reset_collect(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (plan->map[i])
	{
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'Z')
				plan->map[i][j] = 'C';
			j++;
		}
		i++;
		j = 0;
	}
}

int	**create_matrice(t_map *plan)
{
	int	i;
	int	**matrice;

	matrice = malloc(sizeof(int *) * plan->height);
	if (!matrice)
		leave_error("Error\nBad Malloc", &plan);
	i = 0;
	while (i < plan->height)
	{
		matrice[i] = malloc(sizeof(int) * plan->width);
		if (!matrice[i])
		{
			free_matrice(matrice, plan);
			leave_error("Error\nBad Malloc1", &plan);
		}
		zero_matrice(matrice[i], plan);
		i++;
	}
	return (matrice);
}

void	zero_matrice(int *matrice, t_map *plan)
{
	int	i;

	i = 0;
	while (i < plan->width)
	{
		matrice[i] = 0;
		i++;
	}
}

void	free_matrice(int **matrice, t_map *plan)
{
	int	i;

	i = 0;
	if (matrice)
	{
		while (i < plan->height)
		{
			if (matrice[i])
				free(matrice[i]);
			else
				break ;
			i++;
		}
		free(matrice);
	}
}
