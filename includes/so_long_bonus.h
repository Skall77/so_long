/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 12:26:06 by aaudevar          #+#    #+#             */
/*   Updated: 2023/01/04 16:27:32 by aaudevar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>
# include <sys/stat.h>
# include <sys/types.h>

# define IMG_H 32
# define IMG_W 32
# define FLOOR "./textures/floor2.xpm"
# define WALL "./textures/wall2.xpm"
# define COLLECT "./textures/collect2.xpm"
# define EXIT "./textures/exit3.xpm"
# define HERO "./textures/hero2.xpm"
# define HERO_X "./textures/hero_exit.xpm"
# define ENEMY "./textures/enemy.xpm"
# define ENEMY_2 "./textures/enemy_2.xpm"
# define EXIT_2 "./textures/exit4.xpm"
# define EXIT_3 "./textures/exit5.xpm"
# define EXIT_4 "./textures/exit6.xpm"

typedef struct s_point
{
	int						x;
	int						y;
}							t_point;

typedef struct s_map
{
	char					**map;
	t_point					hero;
	t_point					enemy;
	t_point					enemy_2;
	t_point					exit_point;
	int						collectibles;
	int						exit;
	int						sp;
	int						height;
	int						width;
	int						moves;
	void					*mlx;
	void					*mlx_win;
	void					*img_floor;
	void					*img_wall;
	void					*img_collect;
	void					*img_exit;
	void					*img_hero;
	void					*img_hero_exit;
	void					*img_enemy;
	void					*img_enemy_2;
	void					*img_exit_2;
	void					*img_exit_3;
	void					*img_exit_4;
	unsigned long long int	frame;
	int						is_enemy_1;
	int						is_enemy_2;
}							t_map;

void						init_plan(t_map **plan);
void						size_map(t_map *plan, char **argv);
void						leave_error(char *message, t_map **plan);
void						get_map(t_map *plan, char **map, int fd);
void						build_map(t_map *plan, char **map, int i,
								char *line);
void						parse_map(t_map *plan, char **argv);
void						print_map(char **map);
void						free_all(t_map **plan);
void						check_map(t_map *plan);
int							rectangle_map(t_map *plan);
int							check_wall(t_map *plan);
int							check_characters(t_map *plan);
void						check_rest(t_map *plan);
int							is_path_start(t_map *plan);
int							is_safe(int i, int j, t_map *plan);
int							backtracking_ex(t_map *plan, int i, int j,
								int **visited);
int							backtracking_co(t_map *plan, int i, int j,
								int **visited);
void						check_path(t_map *plan);
int							is_path_exit(t_map *plan);
void						reset_collect(t_map *plan);
int							**create_matrice(t_map *plan);
void						free_matrice(int **matrice, t_map *plan);
void						zero_matrice(int *matrice, t_map *plan);
void						free_map(char **map, t_map *plan, int fd,
								char *line);
int							function_no_event(t_map *plan);
int							function_escape_input(int keysym, t_map *plan);
int							function_cross(t_map *plan);
void						init_window(t_map **plan);
void						put_floor(t_map *plan);
void						error_img(t_map **plan);
void						init_imgs(t_map **plan);
void						init_hero(t_map **plan);
void						init_hero_exit(t_map **plan);
void						get_hero_position(t_map *plan);
void						update_map(t_map *plan);
int							victory(t_map *plan);
void						go_up(t_map *plan);
void						go_left(t_map *plan);
void						go_right(t_map *plan);
void						go_down(t_map *plan);
void						shorter_put_img(t_map *plan, int i, int j, char c);
void						free_check(t_map **plan);
void						get_enemy_position(t_map *plan);
void						check_enemy(int i, int j, t_map *plan);
void						move_enemy(t_map *plan);
int							defeat(t_map *plan);
void						move_enemy_2(t_map *plan);
void						check_enemy_2(int i, int j, t_map *plan);
void						get_enemy_2_position(t_map *plan);
void						destroy_image(t_map **plan);
void						init_exit_frames(t_map **plan);
void						check_exit(t_map *plan);
int							update_animation(t_map *plan);
void						destroy_exit(t_map **plan);
void						init_others_exit(t_map **plan);
int							move_more(t_map *plan);
int							move_more_2(t_map *plan);

#endif