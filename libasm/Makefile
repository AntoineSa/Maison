NAME = osef

SRCS = test_strlen.c \
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

OBJS = $(SRCS:.c=.o)
SRCS_PATH = ./tests/
OBJS_PATH = ./tests/
INCL_PATH = ./incl/
LIB_PATH = ./srcs/

CC = gcc
C_FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(SRCS):
	$(CC) $(C_FLAGS) -c $(addprefix $(SRCS_PATH), $@) -I $(INCL_PATH) -o $(addprefix $(OBJS_PATH), $(@:.c=.o))

$(NAME): lib $(SRCS)
	$(CC) $(C_FLAGS) -no-pie -o $(NAME) -I $(INCL_PATH) main.c $(addprefix $(OBJS_PATH), $(OBJS)) $(addprefix $(LIB_PATH), libasm.a)

lib:
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
