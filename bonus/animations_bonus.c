/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:31:27 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/17 12:31:51 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_exit_frames(t_map **plan)
{
	int	height;
	int	width;

	(*plan)->img_exit_2 = mlx_xpm_file_to_image((*plan)->mlx, EXIT_2, &height,
			&width);
	if ((*plan)->img_exit_2 == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy_2);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_hero_exit);
		destroy_image(plan);
	}
	init_others_exit(plan);
	(*plan)->frame = 0;
	check_exit(*plan);
}

void	destroy_exit(t_map **plan)
{
	mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy_2);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_hero_exit);
	destroy_image(plan);
}

void	init_others_exit(t_map **plan)
{
	int	height;
	int	width;

	(*plan)->img_exit_3 = mlx_xpm_file_to_image((*plan)->mlx, EXIT_3, &height,
			&width);
	if ((*plan)->img_exit_3 == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_exit_2);
		destroy_exit(plan);
	}
	(*plan)->img_exit_4 = mlx_xpm_file_to_image((*plan)->mlx, EXIT_4, &height,
			&width);
	if ((*plan)->img_exit_4 == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_exit_2);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_exit_3);
		destroy_exit(plan);
	}
}

void	check_exit(t_map *plan)
{
	int	i;
	int	j;

	i = 0;
	while (plan->map[i])
	{
		j = 0;
		while (plan->map[i][j])
		{
			if (plan->map[i][j] == 'E')
			{
				plan->exit_point.x = i;
				plan->exit_point.y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	update_animation(t_map *plan)
{
	(plan->frame)++;
	if (plan->frame % 31 == 1)
		mlx_put_image_to_window(plan->mlx, plan->mlx_win, plan->img_exit,
			plan->exit_point.y * IMG_W, plan->exit_point.x * IMG_H);
	else if (plan->frame % 31 == 10)
		mlx_put_image_to_window(plan->mlx, plan->mlx_win, plan->img_exit_2,
			plan->exit_point.y * IMG_W, plan->exit_point.x * IMG_H);
	else if (plan->frame % 31 == 20)
		mlx_put_image_to_window(plan->mlx, plan->mlx_win, plan->img_exit_3,
			plan->exit_point.y * IMG_W, plan->exit_point.x * IMG_H);
	else if (plan->frame % 31 == 30)
		mlx_put_image_to_window(plan->mlx, plan->mlx_win, plan->img_exit_4,
			plan->exit_point.y * IMG_W, plan->exit_point.x * IMG_H);
	return (0);
}
