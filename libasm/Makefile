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
OBJS_PATH = ./srcs/
INCL_PATH = ./incl/

AS = nasm
ASFLAGS = -felf64
LD = ld
LDFLAGS = -m elf_i386

NAME = libasm.a

all: $(NAME)

$(SRCS):
	$(AS) $(ASFLAGS) $(addprefix $(SRCS_PATH), $@)
		

$(NAME): $(SRCS)
	ar -rc $(NAME) $(addprefix $(OBJS_PATH), $(OBJS))
	$(LD) $(LDFLAGS) $(addprefix $(OBJS_PATH), $(OBJS))

clean :
	rm -rf $(addprefix $(OBJS_PATH), $(OBJS))

fclean : clean
	rm -f $(NAME)

re : fclean all
