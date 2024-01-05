/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 18:46:21 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/26 16:44:50 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_hero_position(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'P')
			{
				plan->hero.x = i;
				plan->hero.y = j;
			}
			j++;
		}
		i++;
	}
}

void	go_up(t_map *plan)
{
	if (plan->map[plan->hero.x - 1][plan->hero.y] != '1')
	{
		plan->moves++;
		ft_printf("You moved %d times\n", plan->moves);
		plan->hero.x--;
		update_map(plan);
	}
}

void	go_left(t_map *plan)
{
	if (plan->map[plan->hero.x][plan->hero.y - 1] != '1')
	{
		plan->moves++;
		ft_printf("You moved %d times\n", plan->moves);
		plan->hero.y--;
		update_map(plan);
	}
}

void	go_right(t_map *plan)
{
	if (plan->map[plan->hero.x][plan->hero.y + 1] != '1')
	{
		plan->moves++;
		ft_printf("You moved %d times\n", plan->moves);
		plan->hero.y++;
		update_map(plan);
	}
}

void	go_down(t_map *plan)
{
	if (plan->map[plan->hero.x + 1][plan->hero.y] != '1')
	{
		plan->moves++;
		ft_printf("You moved %d times\n", plan->moves);
		plan->hero.x++;
		update_map(plan);
	}
}
