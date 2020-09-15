NAME = osef

SRCS = test_strlen.c \
       test_strcpy.c \
       test_strcmp.c \
       test_write.c \
       test_read.c \
       test_strdup.c \

SRCS_BONUS = test_atoi_base.c \
	     test_lst_push_front.c \
	     test_lst_size.c \
	     test_lst_sort.c \
	     test_lst_remove_if.c \

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS_BONUS:.c=.o)
SRCS_PATH = ./tests/
OBJS_PATH = ./tests/
INCL_PATH = ./incl/
LIB_PATH = ./srcs/

CC = gcc
C_FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(OBJS):
	$(CC) $(C_FLAGS) -c $(addprefix $(SRCS_PATH), $(@:.o=.c)) -I $(INCL_PATH) -o $(addprefix $(OBJS_PATH), $@)

$(BONUS_OBJS):
	$(CC) $(C_FLAGS) -c $(addprefix $(SRCS_PATH), $(@:.o=.c)) -I $(INCL_PATH) -o $(addprefix $(OBJS_PATH), $@)

$(NAME): lib $(OBJS)
	$(CC) $(C_FLAGS) -no-pie -o $(NAME) -I $(INCL_PATH) main.c $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(LIB_PATH), libasm.a)

bonus : lib_bonus $(BONUS_OBJS)
	$(CC) $(C_FLAGS) -no-pie -o $(NAME) -I $(INCL_PATH) main_bonus.c $(addprefix $(OBJS_PATH), $(BONUS_OBJS)) $(addprefix $(LIB_PATH), libasm.a)

lib:
	make -C $(LIB_PATH)

lib_bonus:
	make bonus -C $(LIB_PATH)

clean :
	make clean -C $(LIB_PATH)
	rm -rf $(addprefix $(OBJS_PATH), $(OBJS))

fclean: clean
	make fclean -C $(LIB_PATH)
	rm -f $(NAME)

re:
	make fclean
	make all
