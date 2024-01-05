/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:10:44 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/04 16:34:42 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	get_enemy_2_position(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	plan->is_enemy_2 = 0;
	plan->enemy_2.x = 0;
	plan->enemy_2.y = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'E')
			{
				check_enemy_2(i, j, plan);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_enemy_2(int i, int j, t_map *plan)
{
	if (plan->map[i - 1][j] == '0')
		plan->map[i - 1][j] = 'Z';
	else if (plan->map[i + 1][j] == '0')
		plan->map[i + 1][j] = 'Z';
	else if (plan->map[i][j - 1] == '0')
		plan->map[i][j - 1] = 'Z';
	else if (plan->map[i][j + 1] == '0')
		plan->map[i][j + 1] = 'Z';
	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'Z')
			{
				plan->enemy_2.x = i;
				plan->enemy_2.y = j;
				plan->is_enemy_2 = 1;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy_2(t_map *plan)
{
	if (move_more_2(plan) == 1)
	{
		plan->map[plan->enemy_2.x + 1][plan->enemy_2.y] = 'Z';
		plan->map[plan->enemy_2.x][plan->enemy_2.y] = '0';
		plan->enemy_2.x++;
	}
	else if (move_more_2(plan) == 2)
	{
		plan->map[plan->enemy_2.x - 1][plan->enemy_2.y] = 'Z';
		plan->map[plan->enemy_2.x][plan->enemy_2.y] = '0';
		plan->enemy_2.x--;
	}
	else if (move_more_2(plan) == 3)
	{
		plan->map[plan->enemy_2.x][plan->enemy_2.y + 1] = 'Z';
		plan->map[plan->enemy_2.x][plan->enemy_2.y] = '0';
		plan->enemy_2.y++;
	}
	else if (move_more_2(plan) == 4)
	{
		plan->map[plan->enemy_2.x][plan->enemy_2.y - 1] = 'Z';
		plan->map[plan->enemy_2.x][plan->enemy_2.y] = '0';
		plan->enemy_2.y--;
	}
}

int	move_more_2(t_map *plan)
{
	if (plan->map[plan->enemy_2.x + 1][plan->enemy_2.y] == '0'
		&& plan->enemy_2.x < plan->hero.x)
	{
		return (1);
	}
	else if (plan->map[plan->enemy_2.x - 1][plan->enemy_2.y] == '0'
			&& plan->enemy_2.x > plan->hero.x)
	{
		return (2);
	}
	else if (plan->map[plan->enemy_2.x][plan->enemy_2.y + 1] == '0'
			&& plan->enemy_2.y < plan->hero.y)
	{
		return (3);
	}
	else if (plan->map[plan->enemy_2.x][plan->enemy_2.y - 1] == '0'
			&& plan->enemy_2.y > plan->hero.y)
	{
		return (4);
	}
	return (0);
}
