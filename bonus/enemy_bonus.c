/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:27:55 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/04 16:34:29 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_enemy_position(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	plan->is_enemy_1 = 0;
	plan->enemy.x = 0;
	plan->enemy.y = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'C')
			{
				check_enemy(i, j, plan);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_enemy(int i, int j, t_map *plan)
{
	if (plan->map[i - 1][j] == '0')
		plan->map[i - 1][j] = 'X';
	else if (plan->map[i + 1][j] == '0')
		plan->map[i + 1][j] = 'X';
	else if (plan->map[i][j - 1] == '0')
		plan->map[i][j - 1] = 'X';
	else if (plan->map[i][j + 1] == '0')
		plan->map[i][j + 1] = 'X';
	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'X')
			{
				plan->enemy.x = i;
				plan->enemy.y = j;
				plan->is_enemy_1 = 1;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy(t_map *plan)
{
	if (move_more(plan) == 1)
	{
		plan->map[plan->enemy.x + 1][plan->enemy.y] = 'X';
		plan->map[plan->enemy.x][plan->enemy.y] = '0';
		plan->enemy.x++;
	}
	else if (move_more(plan) == 2)
	{
		plan->map[plan->enemy.x - 1][plan->enemy.y] = 'X';
		plan->map[plan->enemy.x][plan->enemy.y] = '0';
		plan->enemy.x--;
	}
	else if (move_more(plan) == 3)
	{
		plan->map[plan->enemy.x][plan->enemy.y + 1] = 'X';
		plan->map[plan->enemy.x][plan->enemy.y] = '0';
		plan->enemy.y++;
	}
	else if (move_more(plan) == 4)
	{
		plan->map[plan->enemy.x][plan->enemy.y - 1] = 'X';
		plan->map[plan->enemy.x][plan->enemy.y] = '0';
		plan->enemy.y--;
	}
}

int	move_more(t_map *plan)
{
	if (plan->map[plan->enemy.x + 1][plan->enemy.y] == '0'
		&& plan->enemy.x < plan->hero.x)
	{
		return (1);
	}
	else if (plan->map[plan->enemy.x - 1][plan->enemy.y] == '0'
			&& plan->enemy.x > plan->hero.x)
	{
		return (2);
	}
	else if (plan->map[plan->enemy.x][plan->enemy.y + 1] == '0'
			&& plan->enemy.y < plan->hero.y)
	{
		return (3);
	}
	else if (plan->map[plan->enemy.x][plan->enemy.y - 1] == '0'
			&& plan->enemy.y > plan->hero.y)
	{
		return (4);
	}
	return (0);
}
