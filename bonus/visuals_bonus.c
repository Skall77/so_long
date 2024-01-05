/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visuals_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:10:01 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/04 15:56:02 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	init_window(t_map **plan)
{
	int	height;
	int	width;

	(*plan)->mlx = mlx_init();
	if ((*plan)->mlx == NULL)
		leave_error("Error\nBad MLX WINDOW\n", plan);
	(*plan)->mlx_win = mlx_new_window((*plan)->mlx, IMG_W * (*plan)->width,
			IMG_H * (*plan)->height, "so_long");
	if ((*plan)->mlx_win == NULL)
	{
		mlx_destroy_display((*plan)->mlx);
		free((*plan)->mlx);
		leave_error("Error\nBad MLX\n", plan);
	}
	(*plan)->img_floor = mlx_xpm_file_to_image((*plan)->mlx, FLOOR, &height,
			&width);
	if ((*plan)->img_floor == NULL)
		error_img(plan);
	init_imgs(plan);
}

void	init_imgs(t_map **plan)
{
	int	height;
	int	width;

	(*plan)->img_wall = mlx_xpm_file_to_image((*plan)->mlx, WALL, &height,
			&width);
	if ((*plan)->img_wall == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_floor);
		error_img(plan);
	}
	(*plan)->img_collect = mlx_xpm_file_to_image((*plan)->mlx, COLLECT, &height,
			&width);
	if ((*plan)->img_collect == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_floor);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_wall);
		error_img(plan);
	}
	init_hero(plan);
}

void	init_hero(t_map **plan)
{
	int	height;
	int	width;

	(*plan)->img_exit = mlx_xpm_file_to_image((*plan)->mlx, EXIT, &height,
			&width);
	if ((*plan)->img_exit == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_floor);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_wall);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_collect);
		error_img(plan);
	}
	(*plan)->img_hero = mlx_xpm_file_to_image((*plan)->mlx, HERO, &height,
			&width);
	if ((*plan)->img_hero == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_floor);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_wall);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_collect);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_exit);
		error_img(plan);
	}
	init_hero_exit(plan);
}

void	init_hero_exit(t_map **plan)
{
	int	height;
	int	width;

	(*plan)->img_hero_exit = mlx_xpm_file_to_image((*plan)->mlx, HERO_X,
			&height, &width);
	if ((*plan)->img_hero_exit == NULL)
		destroy_image(plan);
	(*plan)->img_enemy = mlx_xpm_file_to_image((*plan)->mlx, ENEMY, &height,
			&width);
	if ((*plan)->img_enemy == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_hero_exit);
		destroy_image(plan);
	}
	(*plan)->img_enemy_2 = mlx_xpm_file_to_image((*plan)->mlx, ENEMY_2, &height,
			&width);
	if ((*plan)->img_enemy_2 == NULL)
	{
		mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy);
		mlx_destroy_image((*plan)->mlx, (*plan)->img_hero_exit);
		destroy_image(plan);
	}
	init_exit_frames(plan);
}

void	destroy_image(t_map **plan)
{
	mlx_destroy_image((*plan)->mlx, (*plan)->img_floor);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_wall);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_collect);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_exit);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_hero);
	error_img(plan);
}
