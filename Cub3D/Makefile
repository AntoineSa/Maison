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

HEADER = cube.h
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
		init_hud \
		get_input \
		look \
		move \
		ray_h \
		ray_v \
		raycast \
		draw_utils \
		draw_window \
		draw_mini_map \
		draw_sprite \
		draw_hud \
		draw_aim \
		screenshot \
		exit

SRCS = $(addsuffix .c, $(FILES))
SRCDIR = srcs/

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

all: $(NAME)

$(NAME) : makelibft  $(addprefix $(OBJDIR), $(OBJS))
	$(CC) -o $(NAME) $(addprefix $(OBJDIR), $(OBJS)) libft/libft.a -L $(MLX_PATH) -lmlx -lXext -lX11 -lbsd -g3 -fsanitize=address

makelibft:
		make -j8 -C $(LIBFT_PATH)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJDIR)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean all
