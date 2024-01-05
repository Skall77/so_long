/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:25:58 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/17 12:22:48 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	leave_error(char *message, t_map **plan)
{
	int	i;

	i = 0;
	if (*plan)
	{
		if ((*plan)->map)
		{
			while ((*plan)->map[i])
			{
				free((*plan)->map[i]);
				i++;
			}
			free((*plan)->map);
		}
		free((*plan));
	}
	ft_printf(message);
	exit(1);
}

void	check_file(int argc, char **argv, t_map *plan)
{
	int	i;

	i = 0;
	if (argc != 2)
		leave_error("Error\nUsage : ./so_long map.ber\n", &plan);
	while (argv[1][i])
		i++;
	i = i - 4;
	if (i <= 0)
		leave_error("Error\nUsage : ./so_long map.ber\n", &plan);
	if (argv[1][i] != '.')
		leave_error("Error\nUsage : ./so_long map.ber\n", &plan);
	i++;
	if (argv[1][i] != 'b')
		leave_error("Error\nUsage : ./so_long map.ber\n", &plan);
	i++;
	if (argv[1][i] != 'e')
		leave_error("Error\nUsage : ./so_long map.ber\n", &plan);
	i++;
	if (argv[1][i] != 'r')
		leave_error("Error\nUsage : ./so_long map.ber\n", &plan);
}

void	free_all(t_map **plan)
{
	int	i;

	i = 0;
	while ((*plan)->map[i])
	{
		free((*plan)->map[i]);
		i++;
	}
	free((*plan)->map);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_collect);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_exit);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_floor);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_hero);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_hero_exit);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_wall);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_enemy_2);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_exit_2);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_exit_3);
	mlx_destroy_image((*plan)->mlx, (*plan)->img_exit_4);
	mlx_destroy_display((*plan)->mlx);
	free((*plan)->mlx);
	free((*plan));
}

void	free_check(t_map **plan)
{
	int	i;

	i = 0;
	while ((*plan)->map[i])
	{
		free((*plan)->map[i]);
		i++;
	}
	free((*plan)->map);
	free((*plan));
}

int	main(int argc, char **argv)
{
	t_map	*plan;

	plan = NULL;
	check_file(argc, argv, plan);
	init_plan(&plan);
	size_map(plan, argv);
	parse_map(plan, argv);
	check_map(plan);
	check_path(plan);
	get_hero_position(plan);
	get_enemy_position(plan);
	get_enemy_2_position(plan);
	init_window(&plan);
	mlx_loop_hook(plan->mlx, &function_no_event, plan);
	mlx_hook(plan->mlx_win, KeyPress, KeyPressMask, &function_escape_input,
		plan);
	mlx_hook(plan->mlx_win, 17, 1L << 17, &function_cross, plan);
	mlx_loop(plan->mlx);
	free_all(&plan);
}
