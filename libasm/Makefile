SRCS = ft_strlen.s \
       ft_strcpy.s \
       ft_strcmp.s \
       ft_write.s \
       ft_read.s \
       ft_strdup.s

SRCS_BONUS = ft_atoi_base.s \
	     ft_list_push_front.s \
	     ft_list_size.s \
	     ft_list_sort.s \
	     ft_list_remove_if.s \

SRCS_MAIN = test_strlen.c \
	    test_strcpy.c \
	    test_strcmp.c \
	    test_write.c \
	    test_read.c \
	    test_strdup.c \
	    test_atoi_base.c \
	    test_lst_push_front.c \
	    test_lst_size.c \
	    test_lst_sort.c \
	    test_lst_remove_if.c \

OBJS = $(SRCS:.s=.o)
BONUS_OBJS = $(SRCS_BONUS:.s=.o)
OBJS_MAIN = $(SRCS_MAIN:.c=.o)

SRCS_PATH = ./srcs/
OBJS_PATH = ./srcs/
MAIN_PATH = ./tests/
INCL_PATH = ./incl/

AS = nasm
ASFLAGS = -felf64
CC = gcc
C_FLAGS = -Wall -Werror -Wextra
#ASFLAGS = -f macho64

NAME = libasm.a

all: $(NAME)

$(SRCS):
	$(AS) $(ASFLAGS) $(addprefix $(SRCS_PATH), $@)

$(SRCS_BONUS):
	$(AS) $(ASFLAGS) $(addprefix $(SRCS_PATH), $@)

$(SRCS_MAIN):
	$(CC) $(C_FLAGS) -c $(addprefix $(MAIN_PATH), $@) -I $(INCL_PATH) -o $(addprefix $(MAIN_PATH), $(OBJS_MAIN))

$(NAME): $(SRCS)
	ar -rc $(NAME) $(addprefix $(OBJS_PATH), $(OBJS))
#	$(LD) $(LDFLAGS) $(addprefix $(OBJS_PATH), $(OBJS))

bonus : $(SRCS) $(SRCS_BONUS)
	ar -rc $(NAME) $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(OBJS_PATH), $(BONUS_OBJS))
#	$(LD) $(LDFLAGS) $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(OBJS_PATH), $(OBJS_BONUS))

main :	bonus $(SRCS_MAIN)
	$(CC) $(C_FLAGS) $(addprefix $(MAIN_PATH), $(OBJS_MAIN)) $(NAME) -I $(INCL_PATH)

clean :
	rm -rf $(addprefix $(OBJS_PATH), $(OBJS))
	rm -rf $(addprefix $(OBJS_PATH), $(BONUS_OBJS))
	rm -rf $(addprefix $(MAIN_PATH), $(OBJS_MAIN))

fclean : clean
	rm -f $(NAME)

re : fclean all
