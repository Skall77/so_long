# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/20 19:04:49 by aaudevar          #+#    #+#              #
#    Updated: 2022/11/20 19:04:49 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC			=	-I ./includes -I ./libft -I ./mlx

LIB			=	-L ./libft -lft -L ./mlx -lmlx -lXext -lX11 -lm -lbsd

SRC			= 	src/so_long.c \
				src/init_plan.c \
				src/check_map.c \
				src/check_path.c \
				src/check_path_2.c \
				src/build_map.c \
				src/mlx_functions.c \
				src/visuals.c \
				src/moves.c \
				src/print.c \

MLX			=	mlx/Makefile.gen

BONUS		=	bonus/so_long_bonus.c \
				bonus/init_plan_bonus.c \
				bonus/check_map_bonus.c \
				bonus/check_path_bonus.c \
				bonus/check_path_two_bonus.c \
				bonus/build_map_bonus.c \
				bonus/mlx_functions_bonus.c \
				bonus/visuals_bonus.c \
				bonus/moves_bonus.c \
				bonus/print_bonus.c \
				bonus/enemy_bonus.c \
				bonus/animations_bonus.c \
				bonus/more_enemy_bonus.c \

OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))

OBJ_BONUS	=	$(patsubst bonus%, obj_bonus%, $(BONUS:.c=.o))

NAME = so_long
LFT = libft/libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: $(MLX) $(LFT) obj $(NAME)

${NAME}: ${OBJ}
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

bonus: $(MLX) $(LFT) obj_bonus ${OBJ_BONUS}
	$(CC) $(CFLAGS) -o ${NAME} ${OBJ_BONUS} $(LIB)

$(MLX):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C mlx
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj: 
	@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(CFLAGS) $(INC) -o $@ -c $<

obj_bonus:
	@mkdir -p obj_bonus

obj_bonus/%.o:	bonus/%.c
				$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@rm -rf $(OBJ_BONUS) obj_bonus
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re : fclean all

.PHONY : all clean fclean re