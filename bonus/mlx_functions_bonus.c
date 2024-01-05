/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:51:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/17 12:32:54 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	function_no_event(t_map *plan)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = ft_itoa(plan->moves);
	str2 = ft_strjoin("You moved ", str);
	free(str);
	str3 = ft_strjoin(str2, " times");
	free(str2);
	usleep(5000);
	put_floor(plan);
	mlx_string_put(plan->mlx, plan->mlx_win, 25, 25, 0x00ffffff, str3);
	free(str3);
	if (plan->map[plan->hero.x][plan->hero.y] == 'Y' && plan->collectibles == 0)
	{
		ft_printf("YOU WIN !\n");
		victory(plan);
	}
	if (plan->hero.x == plan->enemy.x && plan->hero.y == plan->enemy.y)
		defeat(plan);
	if (plan->hero.x == plan->enemy_2.x && plan->hero.y == plan->enemy_2.y)
		defeat(plan);
	return (0);
}

int	function_escape_input(int keysym, t_map *plan)
{
	if (keysym == XK_Escape)
		victory(plan);
	if (keysym == XK_Up || keysym == XK_w)
		go_up(plan);
	if (keysym == XK_Left || keysym == XK_a)
		go_left(plan);
	if (keysym == XK_Right || keysym == XK_d)
		go_right(plan);
	if (keysym == XK_Down || keysym == XK_s)
		go_down(plan);
	return (0);
}

int	function_cross(t_map *plan)
{
	victory(plan);
	return (0);
}

int	victory(t_map *plan)
{
	mlx_clear_window(plan->mlx, plan->mlx_win);
	mlx_destroy_window(plan->mlx, plan->mlx_win);
	free_all(&plan);
	exit(0);
}

int	defeat(t_map *plan)
{
	mlx_clear_window(plan->mlx, plan->mlx_win);
	mlx_destroy_window(plan->mlx, plan->mlx_win);
	free_all(&plan);
	ft_printf("YOU LOSE !\n");
	exit(0);
}
