/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:51:28 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/17 11:04:35 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	function_no_event(t_map *plan)
{
	put_floor(plan);
	if (plan->map[plan->hero.x][plan->hero.y] == 'Y' && plan->collectibles == 0)
	{
		ft_printf("YOU WIN\n");
		victory(plan);
	}
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
