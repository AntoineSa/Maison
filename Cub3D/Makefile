# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 19:03:59 by asablayr          #+#    #+#              #
#    Updated: 2020/03/11 14:24:26 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang-9

CFLAGS = -Wall -Werror -Wextra

HEADER = cube.h \
		def.h \
		libft.h

MLX_PATH = /usr/local/lib/

INCL_PATH = ./incl

LIBFT_PATH = ./libft/

NAME = Cub3D

FILES = cube \
		get_settings \
		set_settings \
		parse \
		parse_map \
		init_player \
		init_game \
		init_sprite \
		get_input \
		look \
		move \
		ray_h \
		ray_v \
		raycast \
		draw_utils \
		draw_window \
		sprite_utils \
		draw_sprite \
		screenshot \
		exit

BONUS_FILES = cube \
		get_settings \
		set_settings \
		parse \
		parse_map \
		bonus_parse \
		bonus_utils \
		init_player \
		init_game \
		init_sprite \
		init_hud \
		get_input \
		move \
		look \
		sprite \
		ray_h \
		ray_v \
		raycast \
		draw_utils \
		draw_window \
		draw_sprite \
		draw_mini_map \
		draw_hud \
		draw_aim \
		screenshot \
		exit

SRCS = $(addsuffix .c, $(FILES))
SRCDIR = srcs/

BONUS = $(addsuffix .c, $(BONUS_FILES))
BONUSDIR = bonus/

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

B_OBJS = $(addsuffix .o, $(BONUS_FILES))
B_OBJDIR = b_objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	make -j8 -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(addprefix $(OBJDIR), $(OBJS)) libft/libft.a -L $(MLX_PATH) -lmlx -lXext -lX11 -lbsd -g3 -fsanitize=address

bonus: $(addprefix $(B_OBJDIR), $(B_OBJS))
	make -j8 -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(addprefix $(B_OBJDIR), $(B_OBJS)) libft/libft.a -L $(MLX_PATH) -lmlx -lXext -lX11 -lbsd -g3 -fsanitize=address
	
makelibft:
		make -j8 -C $(LIBFT_PATH)

$(B_OBJDIR)%.o: $(BONUSDIR)%.c
	mkdir -p $(B_OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJDIR)
	rm -rf $(B_OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
