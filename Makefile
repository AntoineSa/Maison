# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 19:03:59 by asablayr          #+#    #+#              #
#    Updated: 2020/02/22 10:31:55 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

HEADER = cube.h
MLX_PATH = /usr/local/lib/

INCL_PATH = ./incl

NAME = Cub3D

FILES = cube \
		get_settings \
		set_settings \
		parse \
		parse_map \
		init_player \
		init_game \
		get_input \
		look \
		move \
		ray_h \
		ray_v \
		raycast \
		draw_utils \
		draw_window \
		mini_map \
		screenshot \
		exit

SRCS = $(addsuffix .c, $(FILES))
SRCDIR = srcs/

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	$(CC) -o $(NAME) srcs/libft.a -L $(MLX_PATH) -lmlx -framework OpenGL -framework Appkit $(addprefix $(OBJDIR), $(OBJS)) -g3 -fsanitize=address
	
$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) $(addprefix -I, $(INCL_PATH)) -c $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
