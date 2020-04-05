
FILES = main.c \
       srcs/ft_strlen \
       srcs/ft_strcpy \
       srcs/ft_strcmp \
       srcs/ft_write \
       srcs/ft_read \
       srcs/ft_strdup

FILES_BONUS = srcs/ft_atoi_base \
	     srcs/list_push_front \
	     srcs/list_size \
	     srcs/list_sort \
	     srcs/list_remove_if \

SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .c, $(FILES)))
SRCS_PATH = ./srcs/

OBJS = $(addsuffix .o, $(FILES))
OBJS_PATH = ./objs/

AS = nasm
ASLAGS = -f elf -g
LD = ld
LDFLAGS = -m elf_i386

NAME = libasm.a

all: $(NAME)

$(NAME): $(AS) -o $(NAME) $(ASFLAGS)
	$(LD)

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
