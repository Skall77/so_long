/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:36:11 by aaudevar          #+#    #+#             */
/*   Updated: 2022/12/26 16:57:43 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_floor(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			shorter_put_img(plan, i, j, plan->map[i][j]);
			j++;
		}
		i++;
	}
}

void	shorter_put_img(t_map *plan, int i, int j, char c)
{
	if (c == '0')
		mlx_put_image_to_window(plan->mlx, plan->mlx_win,
			plan->img_floor, j * IMG_W, i * IMG_H);
	if (c == '1')
		mlx_put_image_to_window(plan->mlx, plan->mlx_win,
			plan->img_wall, j * IMG_W, i * IMG_H);
	if (c == 'C')
		mlx_put_image_to_window(plan->mlx, plan->mlx_win,
			plan->img_collect, j * IMG_W, i * IMG_H);
	if (c == 'E')
		mlx_put_image_to_window(plan->mlx, plan->mlx_win,
			plan->img_exit, j * IMG_W, i * IMG_H);
	if (c == 'P')
		mlx_put_image_to_window(plan->mlx, plan->mlx_win,
			plan->img_hero, j * IMG_W, i * IMG_H);
	if (c == 'Y')
		mlx_put_image_to_window(plan->mlx, plan->mlx_win,
			plan->img_hero_exit, j * IMG_W, i * IMG_H);
}

void	update_map(t_map *plan)
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
				plan->map[i][j] = '0';
			if (plan->map[i][j] == 'Y')
				plan->map[i][j] = 'E';
			j++;
		}
		i++;
	}
	if (plan->map[plan->hero.x][plan->hero.y] == 'E')
		plan->map[plan->hero.x][plan->hero.y] = 'Y';
	else
	{
		if (plan->map[plan->hero.x][plan->hero.y] == 'C')
			plan->collectibles--;
		plan->map[plan->hero.x][plan->hero.y] = 'P';
	}
}
