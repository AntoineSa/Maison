# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asablayr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 10:20:51 by asablayr          #+#    #+#              #
#    Updated: 2020/01/05 15:51:12 by asablayr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang-9
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

FILES =	ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memccpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_strchr \
		ft_strrchr \
		ft_strncmp \
		ft_strlcpy \
		ft_strlcat \
		ft_strnstr \
		ft_atoi \
		ft_calloc \
		ft_strdup \
		ft_substr \
		ft_strjoin \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_lstnew_bonus \
		ft_lstadd_front_bonus \
		ft_lstsize_bonus \
		ft_lstlast_bonus \
		ft_lstadd_back_bonus \
		ft_lstdelone_bonus \
		ft_lstclear_bonus \
		ft_lstiter_bonus \
		ft_lstmap_bonus \
		get_next_line

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))
OBJDIR = objs/

all: $(NAME)

$(NAME) : $(addprefix $(OBJDIR), $(OBJS))
	@ar -rcs $(NAME) $(addprefix $(OBJDIR), $(OBJS))

$(OBJDIR)%.o: %.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
