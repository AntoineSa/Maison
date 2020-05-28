FILES = ft_strlen \
       ft_strcpy \
       ft_strcmp \
       ft_write \
       ft_read \
       ft_strdup

FILES_BONUS = ft_atoi_base \
	     list_push_front \
	     list_size \
	     list_sort \
	     list_remove_if \

SRCS = $(addprefix $(SRCS_PATH), $(addsuffix .s, $(FILES)))
SRCS_PATH = ./srcs/

OBJS = $(addprefix $(OBJS_PATH), $(SRCS:.s=.o))
OBJS_PATH = ./objs/

AS = nasm
ASFLAGS = -f elf64 -g
LD = ld
LDFLAGS = -m elf_i386

NAME = libasm.a

all: $(NAME)

$(OBJS):
	mkdir -p $(OBJS_PATH)
	$(AS) $(ASFLAGS) $< -o $@
		

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS)

clean :
	rm -rf $(OBJS_PATH)

fclean : clean
	rm -f $(NAME)

re : fclean all
