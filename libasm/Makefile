SRCS = ft_strlen.s \
       ft_strcpy.s \
       ft_strcmp.s \
       ft_write.s \
       ft_read.s \
       ft_strdup.s

SRCS_BONUS = ft_atoi_base.s \
	     list_push_front.s \
	     list_size.s \
	     list_sort.s \
	     list_remove_if.s \

OBJS = $(SRCS:.s=.o)

SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCL_PATH = ./incl/

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
